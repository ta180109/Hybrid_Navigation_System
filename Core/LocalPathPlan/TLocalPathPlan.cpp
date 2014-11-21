#include "TLocalPathPlan.h"
#include <algorithm>

#include <vector>
#include <iostream>
#include <fstream>

//#define METHODSWITCH
#define AVOIDANCERANGE 50
#define DANGERRANGE 5

using namespace SKS_VC2013;
using namespace std;

TLocalPathPlan::TLocalPathPlan()
{
	LocalPathPlan_Initialize();
}

TLocalPathPlan::~TLocalPathPlan()
{

}

void TLocalPathPlan::LocalPathPlan_Initialize(void)
{
 	Lock_Avoid = 0;
	D_Database->AvoidEnableFlag = true;
	D_Database->LaserScanStartAng = -(D_Database->LaserScanRange / 2);
	ScanStartAngle = D_Database->LaserScanStartAng * M_PI / 180.0;
	ScanScale = D_Database->LaserScanSpace * M_PI / 180.0;
	
	//Parameter for VFF
	SafeDistance = 60; 
	SafeArc_D= 50.0;
	SafeArc_A = 50.0 * M_PI / 180.0;
	AvoidConfig1 = 1.2;
	AvoidForce = 130.0 * M_PI / 180.0;
	FixDirect= 0; 
	Stone = new TCoordinate[D_Database->LaserScanNumber];

	//Parameter for VFH
	WindowRange = 3;
	DetecedRange = 100.0;
	ThresholdDis = 10.0;
	WindowErr = 10.0;

}
void TLocalPathPlan::LocalPathPlan_Main(void)
{
	if( D_Database->AvoidEnableFlag)
	{
		#ifdef METHODSWITCH
			D_Database->LocalPlanVector = VFF_Algorithm( D_Database->GlobaPlanlVector);
		#endif
		
		#ifndef METHODSWITCH
			D_Database->LocalPlanVector = VHF_Algorithm( D_Database->GlobaPlanlVector);
		#endif
		
		D_Database->MotionDistance = D_Database->LocalPlanVector.Length();

		D_Database->MotionAngle    = D_Database->LocalPlanVector.Angle();

	}else{
		D_Database->LocalPlanVector = D_Database->GlobaPlanlVector;

		D_Database->MotionDistance = D_Database->LocalPlanVector.Length();

		D_Database->MotionAngle    = D_Database->LocalPlanVector.Angle();

	}
}

TCoordinate TLocalPathPlan::VFF_Algorithm( TCoordinate Goal )
{
	LeftForce  = aVector(0,0);
	RightForce = aVector(0,0);

	double StoneDistance = 0;
	double TmpCutAngle;
	TCoordinate Orien(0,0);

	TCoordinate FixedGoal = Goal;
	

	float LeftCutAngle,RightCutAngle;
	float TmpLen;

	for( int i =0; i< D_Database->LaserScanNumber; i++ )
	{
		Stone[i] = aVector(1,0) << (i * ScanScale  + ScanStartAngle);
				
		if( ( D_Database->LaserData[i].Distance < SafeDistance )&& ( D_Database->LaserData[i].Distance > 0 ) )
		{
			
			TmpCutAngle = NormalizeAngle( Stone[i].Angle() - FixedGoal.Angle() );

			TmpLen      = SafeDistance - D_Database->LaserData[i].Distance;

			if( ( fabs( TmpCutAngle ) * D_Database->LaserData[i].Distance ) <  (SafeArc_A +0.1) * (SafeArc_D + 10) )
			{
				if( i < D_Database->LaserScanNumber/2 )
					if( RightForce.Length() < TmpLen ) {
						RightForce= Stone[i]*TmpLen;
						RightCutAngle= TmpCutAngle;
					}
					if( i > D_Database->LaserScanNumber/2 )
						if( LeftForce.Length() < TmpLen ) {
							LeftForce = Stone[i]*TmpLen;
							LeftCutAngle = TmpCutAngle;
						}

			}
			if( ( fabs( TmpCutAngle ) * D_Database->LaserData[i].Distance ) <  SafeArc_A * SafeArc_D  )
			{
				Stone[i].AssignLength( SafeDistance - D_Database->LaserData[i].Distance );
			}
			else
			{
				Stone[i] = aVector(0,0);
			}
		}
		else {
			Stone[i] = aVector(0,0);
		}

		Orien = Orien + Stone[i];
 		StoneDistance = ( ( Stone[i].Length() > StoneDistance ) ? Stone[i].Length(): StoneDistance );
	}


	if( FixedGoal.Length() < (SafeDistance - StoneDistance) )
		Orien = aVector( 0 ,0 );
	else
		Orien =( Orien.UnitVector() ) * StoneDistance;

	float Config = AvoidConfig1;
	float ForceRate = ( RightForce.Length() == 0 || LeftForce.Length() == 0 )? 0 : LeftForce.Length()/RightForce.Length();
	ForceRate = ForceRate > 1 ? 1/ForceRate : ForceRate;
	if( ForceRate > 0.4 )
	{
		float Left_d  = sin( fabs(LeftCutAngle)  )*(SafeDistance - LeftForce.Length());
		float Right_d = sin( fabs(RightCutAngle) )*(SafeDistance - RightForce.Length());
		if( Left_d + Right_d > 50 )
		{
			Config = 0.6;
		}
	}

	TCoordinate break_vel =  FixedGoal.UnitVector() ;
	if( StoneDistance > SafeDistance )
	{
		break_vel = -1 * FixedGoal;

		Lock_Avoid = 0;
	}
	else
	{
		float value_cross1 = ( break_vel >> M_PI_2 ).cross( Orien );
		float avoid_value  = Config * value_cross1*( FixedGoal.Length() / SafeDistance );
		float value_cross2 = break_vel.cross( Orien );

		if( value_cross2 > 0 )
		{
			break_vel = ( FixedGoal.UnitVector() >> AvoidForce ) * avoid_value;

			Lock_Avoid  = -1;
		}
		else
		{
			break_vel = ( FixedGoal.UnitVector() << AvoidForce ) * avoid_value;
			Lock_Avoid  = 1;
		}
	}
	
	FixedGoal = FixedGoal + break_vel;
	return (FixedGoal);
}
TCoordinate TLocalPathPlan::VHF_Algorithm( TCoordinate Goal ) {
 	
	TCoordinate FixedGoal = Goal;
	vector <double> FixedInfo;
	double FixedDis;

	double AvgDis = 0.0; 
	double TmpWeight = 0.0;

	//Adjust laser information.
	FixedInfo.clear();
	for(int i = 0; i< D_Database->LaserData.size(); i++){
		FixedDis = D_Database->LaserData[i].Distance;// - ThresholdDis;
		if(FixedDis > DetecedRange)
			FixedDis = DetecedRange;
	
		FixedInfo.push_back(FixedDis);
	}

// 	//Use 3 scan line to build small window
	SmallScanWindow.clear();
	for(int i = 0; i < FixedInfo.size()-1; i=i+2) {
 			AvgDis =  (FixedInfo[i] + FixedInfo[i+1] + FixedInfo[i+2] ) / WindowRange ;
			TmpWindow.AverageDis = AvgDis;
			TmpWindow.StartAng = D_Database->LaserData[i].Angle;
			TmpWindow.EndAng = D_Database->LaserData[i+2].Angle;
			TmpWindow.MiddleAng = (TmpWindow.StartAng + TmpWindow.EndAng) / 2.0;
			TmpWindow.GapSize = fabs(TmpWindow.EndAng - TmpWindow.StartAng);

			SmallScanWindow.push_back(TmpWindow);

			AvgDis = 0.0;
	}

	//merge similar window
 	ChooseScanWindow.clear();
	int WindowIndex = 0;
	TmpWindow = SmallScanWindow[0];
	while(WindowIndex+1 <= SmallScanWindow.size()){
		if(fabs(TmpWindow.AverageDis - SmallScanWindow[WindowIndex].AverageDis) < WindowErr){
			TmpWindow = WindowMerge(TmpWindow , SmallScanWindow[WindowIndex]);
			WindowIndex++;
			if(WindowIndex == SmallScanWindow.size())
				ChooseScanWindow.push_back(TmpWindow);
		}else{
			ChooseScanWindow.push_back(TmpWindow);
			TmpWindow = SmallScanWindow[WindowIndex];
			WindowIndex++;
		}
	}
	FixedGoal = VFH_CostFunction(Goal);
	
	return FixedGoal;
}

TCoordinate TLocalPathPlan::VFH_CostFunction(TCoordinate Goal){
	char filename[]="tObslist.txt";
	fstream fp;
	fp.open(filename, ios::out);//開啟檔案
	
	double a = 1.5;
	double b = 1.0;
	double c = 1.5;
	
	Window_Info BestGap;
	TCoordinate LastVector;
	TCoordinate Fix;
	double TmpWeight = DetecedRange + 10.0;
	for(int i = 0; i < ChooseScanWindow.size(); i++){
		ChooseScanWindow[i].MiddleAng = (ChooseScanWindow[i].StartAng + ChooseScanWindow[i].EndAng) / 2.0;

		if(ChooseScanWindow[i].AverageDis < DANGERRANGE){
			ChooseScanWindow[i].GapWeight = DetecedRange*2;
		}else if(ChooseScanWindow[i].AverageDis == DetecedRange){
			ChooseScanWindow[i].GapWeight = -10.0;
		}else{
			ChooseScanWindow[i].GapWeight = DetecedRange - ChooseScanWindow[i].AverageDis;
		}
		double WindowArea = pow(DetecedRange,2) * M_PI * (ChooseScanWindow[i].GapSize / 360.0);
		
		double AngleDiff = M_PI * ((Goal.Angle() - ChooseScanWindow[i].MiddleAng) / 360.0);
		
		double ObsArea = pow(ChooseScanWindow[i].GapWeight, 2) *  M_PI * (ChooseScanWindow[i].GapSize / 360.0);
		ChooseScanWindow[i].GapWeight = (ObsArea / WindowArea) * 100.0 * AngleDiff;
		fp<<ChooseScanWindow[i].GapWeight<<endl;

		if(ChooseScanWindow[i].GapWeight < TmpWeight){
			BestGap.MiddleAng = ChooseScanWindow[i].MiddleAng;
			BestGap.AverageDis = ChooseScanWindow[i].AverageDis;
		}
	}

	if( BestGap.MiddleAng >= 0.0){
		TCoordinate BreakVec(BestGap.MiddleAng);
		BreakVec = -1 * BreakVec * BestGap.AverageDis;
		Fix = a*Goal + b*BreakVec + c*LastVector;
		LastVector = Fix;
	}else{ 
		TCoordinate BreakVec(BestGap.MiddleAng);
		BreakVec =  BreakVec * BestGap.AverageDis;
		Fix = a*Goal + b*BreakVec + c*LastVector;
		LastVector = Fix;
	}
	fp.close();//關閉檔案
	return Fix;
}

TLocalPathPlan::Window_Info TLocalPathPlan::WindowMerge(Window_Info Window_L, Window_Info Window_R){
	Window_Info TmpWindow;

	TmpWindow.AverageDis = ( Window_L.AverageDis + Window_R.AverageDis ) / 2.0;
	TmpWindow.StartAng = Window_L.StartAng;
	TmpWindow.EndAng = Window_R.EndAng;
	TmpWindow.MiddleAng = (TmpWindow.StartAng + TmpWindow.EndAng) / 2.0;
	TmpWindow.GapSize = fabs(TmpWindow.EndAng - TmpWindow.StartAng);
	return TmpWindow;

}