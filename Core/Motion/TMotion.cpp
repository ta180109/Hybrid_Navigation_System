#include <stdio.h>

#include "TMotion.h"

#define ANGLE_1 M_PI/6
#define ANGLE_2 5*(M_PI/6)
#define ANGLE_3 3*(M_PI/2)

#define ROBOT_RADIUS 1.0

using namespace SKS_VC2013;
using namespace std;

TMotion::TMotion():
	mAngle1Sin(-sin(ANGLE_1)),
    mAngle2Sin(-sin(ANGLE_2)),
    mAngle3Sin(-sin(ANGLE_3)),
    mAngle1Cos(cos(ANGLE_1)),
    mAngle2Cos(cos(ANGLE_2)),
    mAngle3Cos(cos(ANGLE_3))
{
	Motion_Initialize();
}

TMotion::~TMotion()
{
}

void TMotion::Motion_Initialize()
{
	D_Database->w  = 0;
}

void TMotion::Motion_Main()
{
	double w = D_Database->w * 48;
	D_Database->MotorSpeed[0] = mAngle1Sin*D_Database->x + mAngle1Cos*D_Database->y - ROBOT_RADIUS * w;
	D_Database->MotorSpeed[1] = mAngle2Sin*D_Database->x + mAngle2Cos*D_Database->y - ROBOT_RADIUS * w;
	D_Database->MotorSpeed[2] = mAngle3Sin*D_Database->x + mAngle3Cos*D_Database->y - ROBOT_RADIUS * w;

}
