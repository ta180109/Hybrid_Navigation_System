//=============================================
//File name: VelocityControl
//
//Author   :Hsieh Ming-Hua
//          Transplant form 2012 SKS project
//Phone    :0921307020
//E-mail   :ta180109@hotmail.com
//Update   :2013/07/05
//
//Function :Use S-Function to decide the robot velocity
//          x-axis parameter:dismax, dismin
//          y-axis parameter:speedmax, speedmin
//===============================================

#ifndef TVelocityControlH
#define TVelocityControlH
//#include "StrategyModule.h"
#include <stdio.h>
//#include <tinyxml.h>
namespace SKS_VC2013 {
	class TVelocityControl //: public StrategyModule
	{

	public:
		TVelocityControl();
		~TVelocityControl();

		//static VelocityControl*  GetInstance() {
			//return m_UniqueInstance;
		//}
		//static string  ParameterReset(void);

		void Velocity_Initialize(void);

		void Velocity_Main(void);

		//int LoadXMLSettings(TiXmlElement* element);  //LoadXMLSettings

	private:

		//static VelocityControl* m_UniqueInstance;

		void VelocityTransform( double, double, double );

		double S_Function( const double& , const double& , const double& , const double&, double );

		double Raise_Function( double V, double Cmd );

		double GoalDistance;

		double GoalAngle;

		double HandleAngle;

		double DistanceMax;

		double DistanceMin;

		double SpeedMax;

		double SpeedMin;

		double ThetaMax;

		double ThetaMin;

		double OmegaMax;

		double OmegaMin;

		double SpeedCmd;

		double SpeedTmp;

	};
}
#endif