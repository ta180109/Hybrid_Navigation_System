#include "../../Database.h"
#include "NavigationSystem.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace SKS_VC2013;
using namespace std;


//Stra_VelocityControl* Stra_VelocityControl::m_UniqueInstance = new Stra_VelocityControl();

NavigationSystem::NavigationSystem()
{

}

NavigationSystem::~NavigationSystem()
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
void NavigationSystem::Initialize(void)
{

}

void NavigationSystem::Process(void)
{
}