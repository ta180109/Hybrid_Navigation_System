#include <stdio.h>
#include "TMotorControl.h"

#define FALSE 0

using namespace SKS_VC2013;

Motors::Motors()
{
}

Motors::~Motors()
{
}

int Motors::Initialize()
{
	return 0;
}


int Motors::OpenDevice(short unsigned device_id)
{
	mErrorCode = 0;
	char device_name[5] = {0,};
	sprintf(device_name, "USB%d", device_id);
	mMotorHandle[device_id] = VCS_OpenDevice("EPOS2", "MAXON SERIAL V2", "USB", device_name, &mErrorCode);

	if(mMotorHandle[device_id] != NULL)
	{
		if(!VCS_SetProtocolStackSettings(mMotorHandle[device_id], 1000000, 500, &mErrorCode))
		{
			fprintf(stderr,  "Open device failure, error code=0x%x\n", mErrorCode);
			return 1;
		}
	}
	else
	{
		fprintf(stderr, "(OpenDevice)Get fault state failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
	return 0;
}

int Motors::SetEnable(short device_id)
{
	mErrorCode = 0;
	int IsInFault = 0;

	if( VCS_GetFaultState(mMotorHandle[device_id], NODE_ID, &IsInFault, &mErrorCode) )
	{
		if( IsInFault && !VCS_ClearFault(mMotorHandle[device_id], NODE_ID, &mErrorCode) )
		{
			fprintf(stderr, "Clear fault failed!, error code=0x%x\n", mErrorCode);
			return 1;
		}

		int IsEnabled = FALSE;
		if( VCS_GetEnableState(mMotorHandle[device_id], NODE_ID, &IsEnabled, &mErrorCode) )
		{
			if( !IsEnabled && !VCS_SetEnableState(mMotorHandle[device_id], NODE_ID, &mErrorCode) )
			{
				fprintf(stderr, "Set enable state failed!, error code=0x%x\n", mErrorCode);
				return 1;
			}
		}
	}
	else
	{
		fprintf(stderr, "(SetEnable)Get fault state failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
	return 0;
}

int Motors::SetDisable(short device_id)
{
	mErrorCode = 0;
	int IsInFault = FALSE;

	if( VCS_GetFaultState(mMotorHandle[device_id], NODE_ID, &IsInFault, &mErrorCode) )
	{
		if( IsInFault && !VCS_ClearFault(mMotorHandle[device_id], NODE_ID, &mErrorCode) )
		{
			fprintf(stderr, "Clear fault failed!, error code=0x%x\n", mErrorCode);
			return 1;
		}

		int IsEnabled = FALSE;
		if( VCS_GetEnableState(mMotorHandle[device_id], NODE_ID, &IsEnabled, &mErrorCode) )
		{
			if( IsEnabled && !VCS_SetDisableState(mMotorHandle[device_id], NODE_ID, &mErrorCode) )
			{
				fprintf(stderr, "Set enable state failed!, error code=0x%x\n", mErrorCode);
				return 1;
			}
		}
	}
	else
	{
		fprintf(stderr, "Get fault state failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////
int Motors::ActivateProfileVelocityMode(short device_id)
{
	mErrorCode = 0;
	if(!VCS_ActivateProfileVelocityMode(mMotorHandle[device_id], NODE_ID,&mErrorCode))
	{
		fprintf(stderr, "Activate Profile Velocity Mode failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
	return 0;
}

int Motors::SetVelocityProfile(short device_id, int ProfileAcceleration, int ProfileDeceleration)
{
	mErrorCode = 0;
	if(!VCS_SetVelocityProfile(mMotorHandle[device_id], NODE_ID,ProfileAcceleration,ProfileDeceleration,&mErrorCode))
	{
		fprintf(stderr, "Set Velocity Profile failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
	return 0;
}

int Motors::SetVelocityRegulatorGain(short device_id, short P, short I)
{
	mErrorCode = 0;
	if(!VCS_SetVelocityRegulatorGain(mMotorHandle[device_id], NODE_ID, P, I, &mErrorCode))
	{
		fprintf(stderr, "Set Velocity Regulator Gain failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
	return 0;
}

int Motors::SetVelocity(short device_id, long TargetVelocity)
{
	mErrorCode = 0;
	if(!VCS_MoveWithVelocity(mMotorHandle[device_id], NODE_ID,TargetVelocity,&mErrorCode))
	{
		fprintf(stderr, "Move With Velocity failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////
int Motors::ActivateCurrentMode(short device_id)
{
	mErrorCode = 0;
	if(!VCS_ActivateCurrentMode(mMotorHandle[device_id], NODE_ID,&mErrorCode))
	{
		fprintf(stderr, "Activate Current Mode failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
	return 0;
}
int Motors::SetEcMotorParameter(short device_id,short NominalCurrent,short MaxOutputCurrent,short ThermalTimeConstant,char NbOfPolePairs)
{
	mErrorCode = 0;
	if(!VCS_SetEcMotorParameter(mMotorHandle[device_id], NODE_ID,NominalCurrent,MaxOutputCurrent,ThermalTimeConstant,NbOfPolePairs,&mErrorCode))
	{
		fprintf(stderr, "Set EcMotor Parameter failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
	return 0;
}
int Motors::SetCurrentMust(short device_id,short CurrentMust)
{
	mErrorCode = 0;
	if(!VCS_SetCurrentMust(mMotorHandle[device_id],NODE_ID,CurrentMust,&mErrorCode))
	{
		fprintf(stderr, "Set Current Must failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
int Motors::HaltVelocityMovement(short device_id)
{
	mErrorCode = 0;
	if(!VCS_HaltVelocityMovement(mMotorHandle[device_id], NODE_ID,&mErrorCode))
	{
		fprintf(stderr, "Halt Velocity Movement failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
	return 0;
}

int Motors::GetIncEncoderParameter(short device_id, DWORD* pEncoderResolution, int* pInvertedPolarity)
{
	mErrorCode = 0;
	if(!VCS_GetIncEncoderParameter(mMotorHandle[device_id], NODE_ID, pEncoderResolution, pInvertedPolarity, &mErrorCode))
	{
		fprintf(stderr, "Get Increment Encoder Parameter failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
	return 0;
}
int Motors::GetPositionIs(short device_id,long* pPositionIs)
{
	mErrorCode = 0;
	if(!VCS_GetPositionIs(mMotorHandle[device_id], NODE_ID,pPositionIs,&mErrorCode))
	{
		fprintf(stderr, "Get Position Is failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
}

int Motors::GetCurrentIs(short device_id, short* pCurrentIs)
{
	mErrorCode = 0;
	if(!VCS_GetCurrentIs(mMotorHandle[device_id], NODE_ID, pCurrentIs, &mErrorCode))
	{
		fprintf(stderr, "Get Current Is Averaged failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
	return 0;
}

int Motors::GetVelocityIs(short device_id, long* pVelocityIs)
{
	mErrorCode = 0;
	if(!VCS_GetVelocityIs(mMotorHandle[device_id], NODE_ID, pVelocityIs, &mErrorCode))
	{
		fprintf(stderr, "Get Current Is Averaged failed!, error code=0x%x\n", mErrorCode);
		return 1;
	}
	return 0;
}

int Motors::OpenDeviceAll()
{
	if(OpenDevice(0) || OpenDevice(1) || OpenDevice(2))
	{
		return 1;
	}
	return 0;
}

int Motors::SetEnableAll()
{
	if(SetEnable(0) || SetEnable(1) || SetEnable(2))
		return 1;
	return 0;
}

int Motors::SetDisableAll()
{
	if(SetDisable(0) || SetDisable(1) || SetDisable(2))
		return 1;
	return 0;
}

int Motors::SetVelocityProfileAll(int ProfileAcceleration, int ProfileDeceleration)
{
	if(
		SetVelocityProfile(0, ProfileAcceleration, ProfileDeceleration) ||
		SetVelocityProfile(1, ProfileAcceleration, ProfileDeceleration) ||
		SetVelocityProfile(2, ProfileAcceleration, ProfileDeceleration))
	{
		return 1;
	}
	return 0;
}

int Motors::SetVelocityAll(long Velocity1, long Velocity2, long Velocity3)
{
	if(
		SetVelocity(0, Velocity1) ||
		SetVelocity(1, Velocity2) ||
		SetVelocity(2, Velocity3))
	{
		return 1;
	}
	return 0;
}

int Motors::ActivateProfileVelocityModeAll()
{
	if(
		ActivateProfileVelocityMode(0) ||
		ActivateProfileVelocityMode(1) ||
		ActivateProfileVelocityMode(2))
	{
		return 1;
	}
	return 0;
}

int Motors::GetIncEncoderParameterAll(
	DWORD* pEncoderResolution1, int* pInvertedPolarity1,
	DWORD* pEncoderResolution2, int* pInvertedPolarity2,
	DWORD* pEncoderResolution3, int* pInvertedPolarity3)
{
	if(
		GetIncEncoderParameter(0, pEncoderResolution1, pInvertedPolarity1) ||
		GetIncEncoderParameter(1, pEncoderResolution2, pInvertedPolarity2) ||
		GetIncEncoderParameter(2, pEncoderResolution3, pInvertedPolarity3))
	{
		return 1;
	}
	return 0;
}