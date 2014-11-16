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
// 	Lock_Avoid = 0;
// 	AvoidLaserData = LocationStatus::LaserData; //given laserdata, scannum is 19
// 	StrategyStatus::FlagAvoidEnable;
}
void TLocalPathPlan::LocalPathPlan_Main(void)
{
	if( D_Database->AvoidEnableFlag)
	{
		
		D_Database->LocalPlanVector = VFF_Algorithm( D_Database->GlobaPlanlVector);
		//D_Database->LocalPlanVector = VHF_Algorithm( D_Database->GlobaPlanlVector);

		D_Database->MotionDistance = D_Database->LocalPlanVector.Length();

		D_Database->MotionAngle    = D_Database->LocalPlanVector.Angle();

	}
}

TCoordinate TLocalPathPlan::VFF_Algorithm( TCoordinate Goal )
{
	int StartAngle_du = -125;
	int ScanLineScale_du = D_Database->LaserScanSpace;
	SafeDistance = 70; 
	int SafeArc_D= 60;
	int SafeArc_A = 60;
	double AvoidConfig1 = 1.2;
	int AvoidForce_du = 130;
	int FixDirect= 0; 

	TCoordinate tmp;

	LeftForce  = aVector(0,0);
	RightForce = aVector(0,0);

	double StoneDistance = 0;
	double TmpCutAngle;

	TCoordinate Orien(0,0);
	vector <TCoordinate> Stone;

	float LeftCutAngle,RightCutAngle;
	float TmpLen;

	char filename[]="tObslist.txt";
	fstream fp;
	fp.open(filename, ios::out);//開啟檔案

	for( int i =0; i< D_Database->LaserData.size() ; i++ )
	{
		tmp = aVector(0,1) << (i * ScanLineScale_du  + StartAngle_du);
		Stone.push_back(tmp);
		
		if( ( D_Database->LaserData[i].Distance < SafeDistance )&& ( D_Database->LaserData[i].Distance > 0 ) )
		{
			TmpCutAngle = NormalizeAngle( Stone[i].Angle() - Goal.Angle() );

			TmpLen      = SafeDistance - D_Database->LaserData[i].Distance;

			if( ( fabs( TmpCutAngle ) * D_Database->LaserData[i].Distance ) <  (SafeArc_A +0.1) * (SafeArc_D + 10) )
			{
				if( i < D_Database->LaserData.size()/2 )
					if( RightForce.Length() < TmpLen ) {
						RightForce= Stone[i]*TmpLen;
						RightCutAngle= TmpCutAngle;
					}
					if( i > D_Database->LaserData.size()/2 )
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
	if( Goal.Length() < (SafeDistance - StoneDistance) )
		Orien = aVector( 0 ,0 );
	else
		Orien =( Orien.UnitVector() ) * StoneDistance;
	float ForceRate = ( RightForce.Length() == 0 || LeftForce.Length() == 0 )? 0 : LeftForce.Length()/RightForce.Length();
	ForceRate = ForceRate > 1 ? 1/ForceRate : ForceRate;
	if( ForceRate > 0.4 )
	{
		float Left_d  = sin( fabs(LeftCutAngle)  )*(SafeDistance - LeftForce.Length());
		float Right_d = sin( fabs(RightCutAngle) )*(SafeDistance - RightForce.Length());
		if( Left_d + Right_d > 50 )
		{
			// int Config = 0.6;
		}
	}

	TCoordinate break_vel =  Goal.UnitVector() ;
	if( StoneDistance > SafeDistance - 15 )
	{
		break_vel = 1*Goal;

		Lock_Avoid = 0;
	}
	else
	{
		float value_cross1 = ( break_vel >> M_PI_2 ).cross( Orien );
		float avoid_value   = 0; /*Config * value_cross1*( Goal.Length()/this->SafeDistance )*/ // need to get the laser information 07/09  ming-hua
		float value_cross2 =   break_vel.cross( Orien );

		if( value_cross2 > 0 )
		{
			break_vel = ( Goal.UnitVector() >> AvoidForce ) * avoid_value;

			Lock_Avoid  = -1;
		}
		else
		{
			break_vel = ( Goal.UnitVector() << AvoidForce ) * avoid_value;
			Lock_Avoid  = 1;
		}
	}
	fp.close();//關閉檔案
	return (Goal+break_vel);
 	//return tmp;
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
