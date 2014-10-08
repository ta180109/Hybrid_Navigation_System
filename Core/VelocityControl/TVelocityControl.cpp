#include "../../Database.h"
#include "TVelocityControl.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace SKS_VC2013;
using namespace std;


//Stra_VelocityControl* Stra_VelocityControl::m_UniqueInstance = new Stra_VelocityControl();

VelocityControl::VelocityControl()
{

}

VelocityControl::~VelocityControl()
{

}
//----------------------------------------------------------------------------xml
/*
int VelocityControl::LoadXMLSettings (TiXmlElement* element) {
    if(element != NULL) {
        element->Attribute("dis_max", &DistanceMax);
        element->Attribute("dis_min", &DistanceMin);
        element->Attribute("spd_max", &SpeedMax);
        element->Attribute("spd_min", &SpeedMin);
        element->Attribute("sita_max", &ThetaMax);
        element->Attribute("sita_min", &ThetaMin);
        element->Attribute("w_max", &OmegaMax);
        element->Attribute("w_min", &OmegaMin);
    }
}
*/
//----------------------------------------------------------------------------
void VelocityControl::Initialize(void)
{

}

void VelocityControl::Process(void)
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

void VelocityControl::VelocityTransform( double dTargetDis, double dTargetCutAng, double Theta )
{
    TCoordinate Vector( dTargetCutAng );

    double Speed = 0;

    if( dTargetDis == 0) {

        double Speed = 0;

        if( dTargetDis == 0)

            Speed = 0;
    }
    else if( dTargetDis > this->DistanceMax )

        Speed = SpeedMax;

    else if( dTargetDis < this->DistanceMin )

        Speed = SpeedMin;

    else

        Speed = S_Function( this->SpeedMax   , this->SpeedMin,

                            this->DistanceMax, this->DistanceMin, dTargetDis);

    if( Speed != 0 && D_Database->FixSpeed != 0 )

        Speed = (D_Database->FixSpeed/100.0)*this->SpeedMax ;

    /*if( Speed > 20 ){

        SpeedCmd = Raise_Function( Speed ,Speed - SpeedCmd );

        this->SpeedTmp++

    }else{

        SpeedCmd = Speed;

    }*/

    D_Database->x = -Speed * Vector.y;

    D_Database->y = Speed * Vector.x;

    //StrategyStatus::PathMotion = Speed * Vector;

    //---------------------------------------------------

    double Omega;

    if( Theta == 0 )

        Omega = 0;

    else if( fabs(Theta) > this->ThetaMax )

        Omega = OmegaMax;

    else if( fabs(Theta) < this->ThetaMin )

        Omega = OmegaMin;

    else

        Omega = S_Function( this->OmegaMax, this->OmegaMin,

                            this->ThetaMax, this->ThetaMin, fabs(Theta) );





    D_Database->PathRotation = (Theta < 0) ? -Omega : Omega;

    //StrategyStatus::w = StrategyStatus::PathRotation;

}

//---------------------------------------------------------------------------

//---------- [tools] S-Function

//---------------------------------------------------------------------------

double VelocityControl::S_Function(const double &TargetMax, const double &TargetMin,

                                        const double &CurrentMax,const double &CurrentMin,

                                        double Data)

{

    return (TargetMax-TargetMin)*((cos(M_PI*(((Data-CurrentMin)/(CurrentMax-CurrentMin))-1))+1)/2 )+TargetMin;

}

//---------------------------------------------------------------------------

//---------- [tools] Raise-Function

//---------------------------------------------------------------------------

double VelocityControl::Raise_Function( double V, double Cmd )

{

    return V * (1-exp((-1*(10/V))*((V+10/V)-Cmd)));

}