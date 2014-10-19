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
//#include <tinyxml.h>
namespace SKS_VC2013 {
	class NavigationSystem //: public StrategyModule
	{

	public:

		NavigationSystem();
		~NavigationSystem();

		//static VelocityControl*  GetInstance() {
		//return m_UniqueInstance;
		//}
		//static string  ParameterReset(void);

		void Initialize(void);

		void Process(void);

		//int LoadXMLSettings(TiXmlElement* element);  //LoadXMLSettings

	private:


	};
}
#endif