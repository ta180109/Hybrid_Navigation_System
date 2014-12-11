#include "TLocalPathPlan.h"
#include <algorithm>

#include <vector>
#include <iostream>
#include <fstream>

#define METHODSWITCH
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
	SafeDistance = 70; 
	SafeArc_D= 70.0;
	SafeArc_A = 70.0 * M_PI / 180.0;
	AvoidConfig1 = 1.2;
	AvoidForce = 80.0 * M_PI / 180.0;
	FixDirect= 0; 
	Stone = new TCoordinate[D_Database->LaserScanNumber];

	//Parameter for VFH
	WindowRange = 3.0;
	DetecedRange = 70.0;
	ThresholdDis = 30.0;
	WindowErr = 5.0;

	ObsScale = 0.8;
	AngScale = 0.2;

}
void TLocalPathPlan::LocalPathPlan_Main(void)
{

	if( D_Database->AvoidEnableFlag)
	{
		#ifdef METHODSWITCH
			D_Database->LocalPlanVector = VFF_Algorithm( D_Database->GlobaPlanlVector);
		#endif
		
		#ifndef METHODSWITCH
			D_Database->LocalPlanVector = VFH_Algorithm( D_Database->GlobaPlanlVector);
		#endif
		
		D_Database->LocalPlanVector = D_Database->LocalPlanVector >> D_Database->RobotDir;

		D_Database->MotionDistance = D_Database->LocalPlanVector.Length();

		D_Database->MotionAngle    = D_Database->LocalPlanVector.Angle();

	}else{
		D_Database->LocalPlanVector = D_Database->LocalPlanVector >> D_Database->RobotDir;

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
TCoordinate TLocalPathPlan::VFH_Algorithm( TCoordinate Goal ) {
	TCoordinate FixedGoal = Goal;
	vector <double> FixedInfo;
	double FixedDis;
	double AvgDis = 0.0; 

	//Adjust laser information.
	FixedInfo.clear();
	for(int i = 0; i< D_Database->LaserData.size(); i++){
		FixedDis = D_Database->LaserData[i].Distance - ThresholdDis;
		if(FixedDis > DetecedRange)
			FixedDis = DetecedRange;
	
		FixedInfo.push_back(FixedDis);
	}

 	//Use 3 scan line to build small window
	SmallScanWindow.clear();
	for(int i = 0; i < FixedInfo.size()-1; i=i+2) {
 			AvgDis =  (FixedInfo[i] + FixedInfo[i+1] + FixedInfo[i+2] ) / WindowRange ;
			TmpWindow.AverageDis = AvgDis;
			TmpWindow.StartAng = D_Database->LaserData[i].Angle;
			TmpWindow.EndAng = D_Database->LaserData[i+2].Angle;
			TmpWindow.MiddleAng = (TmpWindow.StartAng + TmpWindow.EndAng) / 2.0;
			TmpWindow.GapSize = fabs(TmpWindow.EndAng - TmpWindow.StartAng);
			TmpWindow.MergeTime = 0;

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
	
	for(int i = 0; i<ChooseScanWindow.size(); i++){
		fp<<"Distance"<<ChooseScanWindow[i].AverageDis<<endl;
		fp<<"StartAngle"<<ChooseScanWindow[i].StartAng<<endl;
		fp<<"EndAngle"<<ChooseScanWindow[i].EndAng<<endl;
		fp<<"GpaSize"<<ChooseScanWindow[i].GapSize<<endl;
		fp<<"           "<<endl;
	}

	fp<<"------------------------"<<endl;

	TCoordinate FixedGoal = Goal;
	double AvoidAngle;
	double ObsEvaluate;
	double AngEvalute;
	double MinAngle;
	double TmpWeight = 0.0;

	for(int i = 0; i < ChooseScanWindow.size(); i++){
		ChooseScanWindow[i].MiddleAng = (ChooseScanWindow[i].StartAng + ChooseScanWindow[i].EndAng) / 2.0;
		ChooseScanWindow[i].MergeTime = ChooseScanWindow[i].GapSize / (2.0 * D_Database->LaserScanSpace);

		ObsEvaluate = DisWeightNomalize(ChooseScanWindow[i].AverageDis);
		MinAngle = WindowSmallestAng(ChooseScanWindow[i], Goal);
		AngEvalute = AngWeightNomalize(MinAngle, Goal);

		ChooseScanWindow[i].GapWeight =  ObsScale * ObsEvaluate + AngScale * AngEvalute;
		 
		if(ChooseScanWindow[i].GapWeight > TmpWeight){
			TmpWeight = ChooseScanWindow[i].GapWeight;
			AvoidAngle = (0.7*MinAngle + 0.3*ChooseScanWindow[i].MiddleAng);
			//AvoidAngle = MinAngle;
		}
			
		fp<<"Distance"<<ChooseScanWindow[i].AverageDis<<endl;
		fp<<"StartAngle"<<ChooseScanWindow[i].StartAng<<endl;
		fp<<"EndAngle"<<ChooseScanWindow[i].EndAng<<endl;
		fp<<"MergeTime"<<ChooseScanWindow[i].MergeTime<<endl;
		fp<<"GpaSize"<<ChooseScanWindow[i].GapSize<<endl;

		fp<<"ObsEvaluate"<<ObsEvaluate<<endl;
		fp<<"GoalAngle"<<Rad2Deg(Goal.Angle())<<endl;
		fp<<"MinAngle"<<MinAngle<<endl;
		fp<<"AngEvalute"<<AngEvalute<<endl;	
		fp<<"GapWeight"<<ChooseScanWindow[i].GapWeight<<endl;
		fp<<"           "<<endl;
	}

	double GoalAngDe = Rad2Deg(Goal.Angle());
	double Tmp;
	TCoordinate BreakVec;

	fp<<"-----------"<<endl;
	fp<<"Avoid ANG  "<<AvoidAngle<<endl;
	fp<<"Goal ANG  "<<GoalAngDe<<endl;

	if( AvoidAngle >= 0.0){
		if(GoalAngDe >= 0.0){
			Tmp = fabs(Deg2Rad(GoalAngDe - AvoidAngle));
			if(AvoidAngle > GoalAngDe)
				BreakVec = Goal << Tmp;
			else
				BreakVec = Goal >> Tmp;
		}else{
			Tmp = Deg2Rad(AvoidAngle + fabs(GoalAngDe)) ;
			BreakVec = Goal << Tmp;
		}
		FixedGoal = BreakVec;
	}else{
		if(GoalAngDe >= 0.0){
			Tmp = Deg2Rad(GoalAngDe + fabs(AvoidAngle));
			BreakVec = Goal >> Tmp;
		}else{
			Tmp = fabs(Deg2Rad(fabs(AvoidAngle) - fabs(GoalAngDe))) ;
			if(AvoidAngle > GoalAngDe)
				BreakVec = Goal << Tmp;
			else
				BreakVec = Goal >> Tmp;
		}
		FixedGoal = BreakVec;
	}

	fp.close();//關閉檔案
	return FixedGoal;
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

double TLocalPathPlan::DisWeightNomalize(double Distance){
	double DistanceW;

	if(Distance < DANGERRANGE)
		DistanceW = 0.0;
	else
		DistanceW = (Distance / DetecedRange) * 100.0;

	return DistanceW;
}

double TLocalPathPlan::AngWeightNomalize(double Angle, TCoordinate Goal){
	double AngleW;

	double GoalAngDeg = Rad2Deg(Goal.Angle());
		AngleW = ((180.0 - fabs(GoalAngDeg - Angle)) / 180.0) * 100.0;
	
	return AngleW;
}
double TLocalPathPlan::WindowSmallestAng(Window_Info Win, TCoordinate Goal){
	#define MIN_3(a,b,c) a > b ?(b > c ?c : b):(a > c ?c:a)
	
	double GoalAng = (Goal.Angle() / M_PI) * 180.0;
	double Adj_StartAng;
	double Adj_EndAng;
	double Adj_Middle;

	if(Win.MergeTime > 7){
		Adj_StartAng = Win.StartAng + 10*D_Database->LaserScanSpace;
		Adj_EndAng = Win.EndAng - 10*D_Database->LaserScanSpace;
		Adj_Middle = (Adj_StartAng + Adj_EndAng) / 2.0;

		double Goal2AngL = fabs(GoalAng - Adj_StartAng);
		double Goal2AngM = fabs(GoalAng - Adj_Middle);
		double Goal2AngR = fabs(GoalAng - Adj_EndAng);

		double Tmp = MIN_3(Goal2AngL,Goal2AngM,Goal2AngR);

		if(Tmp == Goal2AngL)
			return Adj_StartAng;
		else if(Tmp == Goal2AngM)
			return Adj_Middle;
		else if(Tmp == Goal2AngR)
			return Adj_EndAng;
		else
			return Adj_Middle;

	}else if(Win.MergeTime > 5 && Win.MergeTime < 7){
		Adj_StartAng = Win.StartAng + 6*D_Database->LaserScanSpace;
		Adj_EndAng = Win.EndAng - 6*D_Database->LaserScanSpace;
		Adj_Middle = (Adj_StartAng + Adj_EndAng) / 2.0;

		double Goal2AngL = fabs(GoalAng - Adj_StartAng);
		double Goal2AngM = fabs(GoalAng - Adj_Middle);
		double Goal2AngR = fabs(GoalAng - Adj_EndAng);
		 	
		double Tmp = MIN_3(Goal2AngL,Goal2AngM,Goal2AngR);
		 
		if(Tmp == Goal2AngL)
		 	return Adj_StartAng;
		else if(Tmp == Goal2AngM)
		 	return Adj_Middle;
		else if(Tmp == Goal2AngR)
		 	return Adj_EndAng;
		else
		 	return Adj_Middle;

	}else if(Win.MergeTime > 3 && Win.MergeTime<5){
		Adj_StartAng = Win.StartAng + 2*D_Database->LaserScanSpace;
		Adj_EndAng = Win.EndAng - 2*D_Database->LaserScanSpace;
		Adj_Middle = (Adj_StartAng + Adj_EndAng) / 2.0;

		double Goal2AngL = fabs(GoalAng - Adj_StartAng);
		double Goal2AngM = fabs(GoalAng - Adj_Middle);
		double Goal2AngR = fabs(GoalAng - Adj_EndAng);

		double Tmp = MIN_3(Goal2AngL,Goal2AngM,Goal2AngR);

		if(Tmp == Goal2AngL)
			return Adj_StartAng;
		else if(Tmp == Goal2AngM)
			return Adj_Middle;
		else if(Tmp == Goal2AngR)
			return Adj_EndAng;
		else
			return Adj_Middle;
	
	
	}else{
		double Goal2AngL = fabs(GoalAng - Win.StartAng);
		double Goal2AngM = fabs(GoalAng - Win.MiddleAng);
		double Goal2AngR = fabs(GoalAng - Win.EndAng);

		double Tmp = MIN_3(Goal2AngL,Goal2AngM,Goal2AngR);

		if(Tmp == Goal2AngL)
			return Win.StartAng;
		else if(Tmp == Goal2AngM)
			return Win.MiddleAng;
		else if(Tmp == Goal2AngR)
			return Win.EndAng;
		else
			return Win.MiddleAng;
	}

}

double TLocalPathPlan::Deg2Rad(double AngleDeg){
	double AgngleRad;

	AgngleRad = M_PI * (AngleDeg / 180.0);

	return AgngleRad;
}

double TLocalPathPlan::Rad2Deg(double AngleRad){
	double AngleDeg;

	AngleDeg = 180.0 * (AngleRad / M_PI);

	return AngleDeg;
}