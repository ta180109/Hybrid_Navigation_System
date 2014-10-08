#ifndef _MOTORS_H_
#define _MOTORS_H_

#include "Definitions.h"

namespace SKS_VC2013
{
class Motors
{
private:
    static const short unsigned int NODE_ID = 1;
    static const bool DEBUG_PRINT = false;

    void* mMotorHandle[3];

    DWORD mErrorCode;

public:
    static const short unsigned NUMBER_OF_MOTORS = 3;

    Motors();
    ~Motors();

    int Initialize();

    int OpenDevice(short unsigned);
    int SetEnable(short);
    int SetDisable(short);
    int SetVelocityProfile(short, int, int);
    int SetVelocity(short, long);
    int SetVelocityRegulatorGain(short, short, short);
    int ActivateProfileVelocityMode(short);
    int ActivateCurrentMode(short);
    int SetEcMotorParameter(short,short,short,short,char);
    int SetCurrentMust(short,short);
    int HaltVelocityMovement(short);
    int GetIncEncoderParameter(short, DWORD*, int*);
    int GetPositionIs(short ,long*);
    int GetCurrentIs(short, short*);
    int GetVelocityIs(short, long*);

    int SetEnableAll();
    int SetDisableAll();
    int OpenDeviceAll();
    int SetVelocityProfileAll(int, int);
    int SetVelocityAll(long, long, long);
    int ActivateProfileVelocityModeAll();
    int HaltVelocityMovementAll();
    int GetIncEncoderParameterAll(DWORD*, int*, DWORD*, int*, DWORD*, int*);
};
}

#endif