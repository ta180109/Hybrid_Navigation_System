#include "NavigationSystem.h"

using namespace SKS_VC2013;
using namespace std;

TNavigationSystem::TNavigationSystem()
{
	NavigationSystem_Initialize();
	AStar = new TAStar();
	LocalPathPlan = new TLocalPathPlan();
	VelocityControl = new TVelocityControl();
	Motion = new TMotion();
}

TNavigationSystem::~TNavigationSystem()
{

}

void TNavigationSystem::NavigationSystem_Initialize(void)
{
	D_Database->AvoidEnableFlag = true;
	D_Database->LaserData = D_Database->Sim_Laser;
}

void TNavigationSystem::NavigationSystem_Main(void)
{

	AStar->AStar_Main();
	LocalPathPlan->LocalPathPlan_Main();
	VelocityControl->Velocity_Main();
	Motion->Motion_Main();

}
