#include "TLocalPathPlan.h"
#include <algorithm>

#include <vector>
#include <iostream>
#include <fstream>

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
	D_Database->LaserScanStartAng = -125;

	ScanStartAngle = D_Database->LaserScanStartAng * M_PI / 180.0;
	ScanScale = D_Database->LaserScanSpace * M_PI / 180.0;
	SafeDistance = 60; 
	SafeArc_D= 50.0;
	SafeArc_A = 50.0 * M_PI / 180.0;
	AvoidConfig1 = 1.2;
	AvoidForce = 130.0 * M_PI / 180.0;
	FixDirect= 0; 

	Stone = new TCoordinate[D_Database->LaserScanNumber];
}
void TLocalPathPlan::LocalPathPlan_Main(void)
{
	if( D_Database->AvoidEnableFlag)
	{
		
		D_Database->LocalPlanVector = VFF_Algorithm( D_Database->GlobaPlanlVector);
		//D_Database->LocalPlanVector = VHF_Algorithm( D_Database->GlobaPlanlVector);

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

	TCoordinate TargetGoal = Goal; 

	float LeftCutAngle,RightCutAngle;
	float TmpLen;

	for( int i =0; i< D_Database->LaserScanNumber; i++ )
	{
		Stone[i] = aVector(1,0) << (i * ScanScale  + ScanStartAngle);
				
		if( ( D_Database->LaserData[i].Distance < SafeDistance )&& ( D_Database->LaserData[i].Distance > 0 ) )
		{
			
			TmpCutAngle = NormalizeAngle( Stone[i].Angle() - TargetGoal.Angle() );

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


	if( TargetGoal.Length() < (SafeDistance - StoneDistance) )
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

	TCoordinate break_vel =  TargetGoal.UnitVector() ;
	if( StoneDistance > SafeDistance )
	{
		break_vel = -1 * TargetGoal;

		Lock_Avoid = 0;
	}
	else
	{
		float value_cross1 = ( break_vel >> M_PI_2 ).cross( Orien );
		float avoid_value  = Config * value_cross1*( TargetGoal.Length() / SafeDistance );
		float value_cross2 = break_vel.cross( Orien );

		if( value_cross2 > 0 )
		{
			break_vel = ( TargetGoal.UnitVector() >> AvoidForce ) * avoid_value;

			Lock_Avoid  = -1;
		}
		else
		{
			break_vel = ( TargetGoal.UnitVector() << AvoidForce ) * avoid_value;
			Lock_Avoid  = 1;
		}
	}
	return (TargetGoal+break_vel);
}

TCoordinate TLocalPathPlan::VHF_Algorithm( TCoordinate Goal ) {

	TCoordinate FixedGoal = Goal;
	TCoordinate Tmp;
	vector <VecGaplist> ObstacleList; 
	double ObstacleDis;
	double ObstcalAng;
	ObstacleList.clear();

	for(int i = 1; i < D_Database->LaserData.size()-1; i++) {
	
		ObstacleDis = (D_Database->LaserData[i-1].Distance + D_Database->LaserData[i].Distance + D_Database->LaserData[i+1].Distance) / 3;
		ObstcalAng = D_Database->LaserData[i].Angle;
		
		if(ObstacleDis < AVOIDANCERANGE){
			Tmp =(TCoordinate(D_Database->LaserData[i].Angle) * ObstacleDis);
			ObstacleList.push_back(VecGaplist(Tmp, Tmp.Angle()));
		}
	}

	char filename[]="tObslist.txt";
	fstream fp;
	fp.open(filename, ios::out);//開啟檔案

	//for(int i=0;i<ObstacleList.size();i++){
		//fp<< ObstacleList[i].vec.x << ObstacleList[i].vec.y << ObstacleList[i].ang<<endl;
		fp <<ObstacleList.size()<<endl;
	//}
 	fp.close();//關閉檔案
 	return FixedGoal;
}
