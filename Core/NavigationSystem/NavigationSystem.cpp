#include "NavigationSystem.h"

using namespace SKS_VC2013;
using namespace std;

TNavigationSystem::TNavigationSystem()
{
	AStar = new TAStar();
	VelocityControl = new TVelocityControl();
	Motion = new TMotion();
}

TNavigationSystem::~TNavigationSystem()
{

}

void TNavigationSystem::NavigationSystem_Initialize(void)
{

}

void TNavigationSystem::NavigationSystem_Main(void)
{
	AStar->AStar_Main();

	//VelocityControl->Velocity_Main();
	//Motion->Motion_Main();
	
	
}