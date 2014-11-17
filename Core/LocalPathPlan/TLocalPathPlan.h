//=============================================
//File name: LocalPathPlan
//
//Author   :Hsieh Ming-Hua
//Phone    :0921307020
//E-mail   :ta180109@hotmail.com
//Update   :2014/10/19
//
//Function :Local avoidance
//===============================================
#ifndef TLOCALPATHPLANH
#define TLOCALPATHPLANH
#include "../../TCoordinate/TCoordinate.h"
#include "../../Database.h"

#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

namespace SKS_VC2013 {
	class VecGaplist {
	public:
		TCoordinate vec;
		double ang;
		VecGaplist(TCoordinate vec, double ang) {
			this->vec = vec;
			this->ang = ang;
		}
		inline bool operator < (const VecGaplist &rhs) const {
			return ang < rhs.ang;
		}
	};
	class TLocalPathPlan
	{
	public:

		TLocalPathPlan();
		~TLocalPathPlan();

		void LocalPathPlan_Initialize(void);

		void LocalPathPlan_Main(void);

	private:

		TCoordinate VFF_Algorithm( TCoordinate OrigTarget );

		TCoordinate VHF_Algorithm( TCoordinate OrigTarget);

		TCoordinate LeftForce, RightForce;

		vector<long> AvoidLaserData;

		int AvoidScanLineNum;

		double ScanStartAngle;

		double ScanScale;

		int SafeDistance;

		double SafeArc_D;

		double SafeArc_A;

		double AvoidConfig1;

		double AvoidForce;

		int FixDirect;

		int Config;

		int Lock_Avoid;

		TCoordinate *Stone;

	};
}

#endif
