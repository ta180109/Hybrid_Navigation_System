#include "TLocalPathPlan.h"
#include <algorithm>
#define Def_SafeRadiusStart 15

using namespace SKS_VC2013;
using namespace std;

TLocalPathPlan::TLocalPathPlan()
{
	LocalPathPlan_Initialize();
}

TLocalPathPlan::~TLocalPathPlan()
{

}

// int Stra_Avoid::LoadXMLSettings (TiXmlElement* element) {
// 	if(element != NULL) {
// 		element->Attribute("StartAngle_du", &ScanStartAngle);
// 		element->Attribute("ScanLineSize", &AvoidScanLineNum);
// 		element->Attribute("ScanLineScale_du", &ScanScale);
// 		element->Attribute("SafeRange", &SafeDistance);
// 		element->Attribute("SafeArc_D", &SafeArc_D);
// 		element->Attribute("SafeArc_A", &SafeArc_A);
// 		element->Attribute("AvoidConfig1", &AvoidConfig1);
// 		element->Attribute("AvoidForce_du", &AvoidForce);
// 		element->Attribute("FixDirect", &FixDirect);
// 	}
// 	return 0;
// }

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
		//this->ScanLine = NULL ;//Info->HdwInfo->LaserInfo.ScanArray;

		//AvoidLaserData = LocationStatus::LaserData; //given laserdata, scannum is 19

		//StrategyStatus::GoalVector = StrategyStatus::Goal1;
		
		//D_Database->LocalPlanVector = D_Database->GlobaPlanlVector;
		
		D_Database->LocalPlanVector = VFF_Algorithm( D_Database->GlobaPlanlVector);
		//D_Database->LocalPlanVector = VHF_Algorithm( D_Database->GlobaPlanlVector);

		D_Database->MotionDistance = D_Database->LocalPlanVector.Length();

		D_Database->MotionAngle    = D_Database->LocalPlanVector.Angle();

	}
}

TCoordinate TLocalPathPlan::VFF_Algorithm( TCoordinate Goal )
{
	TCoordinate tmp = Goal;
// 	LeftForce  = aVector(0,0);
// 	RightForce = aVector(0,0);
// 
// 	double StoneDistance = 0;
// 	double TmpCutAngle;
// 
// 	TCoordinate Orien(0,0);
// 
// 	float LeftCutAngle,RightCutAngle;
// 	float TmpLen;
// 
// 	for( int i =0; i< this->AvoidScanLineNum ; i++ )
// 	{
// 		this->Stone[i] = aVector(1,0) << (i*this->ScanScale + this->ScanStartAngle);
// 
// 		if( (  AvoidLaserData[i] < this->SafeDistance )&& ( AvoidLaserData[i] > 0 ) )
// 		{
// 			TmpCutAngle = NormalizeAngle( this->Stone[i].Angle() - Goal.Angle() );
// 
// 			TmpLen      = this->SafeDistance - AvoidLaserData[i];
// 
// 			if( ( fabs( TmpCutAngle ) * AvoidLaserData[i] ) <  (SafeArc_A +0.1) * (SafeArc_D + 10) )
// 			{
// 				if( i < AvoidScanLineNum/2 )
// 					if( RightForce.Length() < TmpLen ) {
// 						RightForce= Stone[i]*TmpLen;
// 						RightCutAngle= TmpCutAngle;
// 					}
// 					if( i > AvoidScanLineNum/2 )
// 						if( LeftForce.Length() < TmpLen ) {
// 							LeftForce = Stone[i]*TmpLen;
// 							LeftCutAngle = TmpCutAngle;
// 						}
// 
// 			}
// 			if( ( fabs( TmpCutAngle ) * AvoidLaserData[i] ) <  this->SafeArc_A * this->SafeArc_D  )
// 			{
// 				this->Stone[i].AssignLength( this->SafeDistance - AvoidLaserData[i] );
// 			}
// 			else
// 			{
// 				this->Stone[i] = aVector(0,0);
// 			}
// 		}
// 		else {
// 			this->Stone[i] = aVector(0,0);
// 		}
// 		Orien = Orien + this->Stone[i];
// 		StoneDistance = ( ( this->Stone[i].Length() > StoneDistance ) ? this->Stone[i].Length(): StoneDistance );
// 	}
// 	if( Goal.Length() < (this->SafeDistance - StoneDistance) )
// 		Orien = aVector( 0 ,0 );
// 	else
// 		Orien =( Orien.UnitVector() ) * StoneDistance;
// 	float ForceRate = ( RightForce.Length() == 0 || LeftForce.Length() == 0 )? 0 : LeftForce.Length()/RightForce.Length();
// 	ForceRate = ForceRate > 1 ? 1/ForceRate : ForceRate;
// 	if( ForceRate > 0.4 )
// 	{
// 		float Left_d  = sin( fabs(LeftCutAngle)  )*(SafeDistance - LeftForce.Length());
// 		float Right_d = sin( fabs(RightCutAngle) )*(SafeDistance - RightForce.Length());
// 		if( Left_d + Right_d > 50 )
// 		{
// 			// int Config = 0.6;
// 		}
// 	}
// 
// 	TCoordinate break_vel =  Goal.UnitVector() ;
// 	if( StoneDistance > SafeDistance - Def_SafeRadiusStart )
// 	{
// 		break_vel = -1*Goal;
// 
// 		Lock_Avoid = 0;
// 	}
// 	else
// 	{
// 		float value_cross1 = ( break_vel >> M_PI_2 ).cross( Orien );
// 		float avoid_value   = 0; /*Config * value_cross1*( Goal.Length()/this->SafeDistance )*/ // need to get the laser information 07/09  ming-hua
// 		float value_cross2 =   break_vel.cross( Orien );
// 
// 		if( value_cross2 > 0 )
// 		{
// 			break_vel = ( Goal.UnitVector() >> AvoidForce ) * avoid_value;
// 
// 			Lock_Avoid  = -1;
// 		}
// 		else
// 		{
// 			break_vel = ( Goal.UnitVector() << AvoidForce ) * avoid_value;
// 			Lock_Avoid  = 1;
// 		}
// 	}
// 
 	return tmp;
}

TCoordinate TLocalPathPlan::VHF_Algorithm( TCoordinate Goal ) {

	TCoordinate tmp = Goal;
// 	vector<VecGaplist> AvoidVector;
// 	TCoordinate Tmp;
// 	double AvgDis = 0.0;
// 	double AvoidDis = 40.0;
// 
// 	for(int i = 3; i < AvoidLaserData.size() - 3; i++) {
// 		AvgDis = AvoidLaserData[i-3] + AvoidLaserData[i-2] + AvoidLaserData[i-1] + AvoidLaserData[i] +
// 			AvoidLaserData[i+3] + AvoidLaserData[i+2] + AvoidLaserData[i+1];
// 		AvgDis /= 7;
// 
// 		if(AvgDis < AvoidDis) {
// 			Tmp =(TCoordinate(ScanStartAngle + i*ScanScale) * AvgDis) + Goal;
// 			AvoidVector.push_back(VecGaplist(Tmp, Tmp.Angle()));
// 			sort(AvoidVector.begin(),AvoidVector.end());
// 		}
// 	}
 	return tmp;
}
