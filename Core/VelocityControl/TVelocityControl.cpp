#include "../../Database.h"
#include "TVelocityControl.h"


#define DistanceMax 100
#define DistanceMin 10 
#define SpeedMax 200
#define	SpeedMin 30 
#define	ThetaMax 1.047197552 
#define	ThetaMin 0.05 
#define	OmegaMax 21
#define	OmegaMin 9

#define _USE_MATH_DEFINES
#include <math.h>

using namespace SKS_VC2013;
using namespace std;


//stra_velocitycontrol* stra_velocitycontrssol::m_uniqueinstance = new stra_velocitycontrol();

TVelocityControl::TVelocityControl()
{
	D_Database->FixSpeed = 0.0;
}

TVelocityControl::~TVelocityControl()
{

}

void TVelocityControl::Velocity_Initialize(void)
{

}

void TVelocityControl::Velocity_Main(void)
{
#ifndef Def_OMNIDIRECTION_SYSTEM
	
    if( D_Database->MotionDistance != 0 )
    {
        if( D_Database->FlagForward )
        {
            D_Database->Direction = D_Database->MotionAngle;
        }
        else
        {
            if( D_Database->MotionAngle > M_PI_2)
            {

                D_Database->Direction = D_Database->MotionAngle - M_PI ;

            }

            else if( D_Database->MotionAngle < -M_PI_2)

            {

                D_Database->Direction = D_Database->MotionAngle + M_PI ;

            }

            else

            {

                D_Database->Direction = D_Database->MotionAngle;

            }
        }

    }

#endif

    //------------------------------------------------------------------------

    VelocityTransform( D_Database->MotionDistance, D_Database->MotionAngle, D_Database->Direction );
}


//-----------------------------------------------------------------------------

void TVelocityControl::VelocityTransform( double dTargetDis, double dTargetCutAng, double Theta )
{


    TCoordinate Vector( dTargetCutAng );

    double Speed = 0;

    if( dTargetDis == 0) {

        double Speed = 0;

        if( dTargetDis == 0)

            Speed = 0;
    }
    else if( dTargetDis > DistanceMax ){

        Speed = SpeedMax;

	}else if( dTargetDis < DistanceMin )

        Speed = SpeedMin;

    else

        Speed = S_Function( SpeedMax   , SpeedMin,

                            DistanceMax, DistanceMin, dTargetDis);

    if( Speed != 0 && D_Database->FixSpeed != 0 )

        Speed = (D_Database->FixSpeed/100.0)*SpeedMax ;

    /*if( Speed > 20 ){

        SpeedCmd = Raise_Function( Speed ,Speed - SpeedCmd );

        this->SpeedTmp++

    }else{

        SpeedCmd = Speed;

    }*/


     D_Database->x = Speed * Vector.y;
     D_Database->y = Speed * Vector.x;

    //StrategyStatus::PathMotion = Speed * Vector;

    //---------------------------------------------------

    double Omega;

    if( Theta == 0 )

        Omega = 0;

    else if( fabs(Theta) > ThetaMax )

        Omega = OmegaMax;

    else if( fabs(Theta) < ThetaMin )

        Omega = OmegaMin;

    else

        Omega = S_Function( OmegaMax, OmegaMin,

                            ThetaMax, ThetaMin, fabs(Theta) );





    D_Database->PathRotation = (Theta < 0) ? -Omega : Omega;

    //D_Database->w = D_Database->PathRotation;

}

//---------------------------------------------------------------------------

//---------- [tools] S-Function

//---------------------------------------------------------------------------

double TVelocityControl::S_Function(const double &TargetMax, const double &TargetMin,

                                        const double &CurrentMax,const double &CurrentMin,

                                        double Data)

{

    return (TargetMax-TargetMin)*((cos(M_PI*(((Data-CurrentMin)/(CurrentMax-CurrentMin))-1))+1)/2 )+TargetMin;

}

//---------------------------------------------------------------------------

//---------- [tools] Raise-Function

//---------------------------------------------------------------------------

double TVelocityControl::Raise_Function( double V, double Cmd )

{

    return V * (1-exp((-1*(10/V))*((V+10/V)-Cmd)));

}