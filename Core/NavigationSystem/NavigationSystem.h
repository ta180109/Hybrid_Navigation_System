//=============================================
//File name: NavigationSystem
//
//Author   :Hsieh Ming-Hua
//Phone    :0921307020
//E-mail   :ta180109@hotmail.com
//Update   :2014/10/19
//
//Function :Do global path planning and local avoidance
//===============================================

#ifndef NavigationSystemH
#define NavigationSystemH
//#include "StrategyModule.h"
#include <stdio.h>
#include "../../stdAfx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "../../Database.h"
#include "../../Core/AStar/TAStar.h"
#include "../../Core/VelocityControl/TVelocityControl.h"
#include "../../Core/Motion/TMotion.h"

//#include <tinyxml.h>
namespace SKS_VC2013 {
	class TNavigationSystem
	{

	public:

		TNavigationSystem();
		~TNavigationSystem();

		TAStar *AStar;
		TVelocityControl *VelocityControl;
		TMotion *Motion;
		

		void NavigationSystem_Initialize(void);

		void NavigationSystem_Main(void);

	private:


	};
}
#endif