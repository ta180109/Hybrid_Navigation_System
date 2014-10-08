//---------------------------------------------------------------------------
//==============================================================================
// File Name: TLaxer UTM-30LX
//
// Author   : Yu ChiaJun  
// E-mail   : ChiaJun.Yu@gmail.com 
//
// Modifier : Yu ChiaJun
// Phone    : 0963356326
//
// Update   : 2011/05/11
// Function : This model is transformation laser packet for Hokuyo 
//
//==============================================================================
//---------------------------------------------------------------------------

#ifndef TLaser_HOKUYOH
#define TLaser_HOKUYOH

#define defNewLine 0x0A

#define def_30LX_StartStep 0
#define def_30LX_EndStep 1080
#define def_30LX_Resolution 0.25 * M_PI / 180.0
#define def_30LX_StartAngle -135 * M_PI / 180.0

#define def_04LX_StartStep 0
#define def_04LX_EndStep 768
#define def_04LX_Resolution 0.36 * M_PI / 180.0
#define def_04LX_StartAngle -138.24 * M_PI / 180.0

#define def_LaserScale 10.0
//===========================================================================
//---------------------------------------------------------------------------
inline unsigned char LaserEncoding( const char &Binary ){ return (( Binary & 0x3f ) + 0x30); }
inline unsigned char LaserDecoding( const char &ASCII  ){ return (( ASCII - 0x30 ) & 0x3f); }

typedef struct
{
	int Start, End, Cluster;
	int Interval;
	int NumOfScans;

}tsLaserCommand;

typedef struct
{
	bool FlagRenew;
	int  Number;
	double Resolution;
	double LiftBorder,RightBorder;
	double StartAngle;
	double ScanRadius;

	int *Data;
	double *Angle;

}tsLaserInfo;

class TLaser_HOKUYO
{

public:
	TLaser_HOKUYO(int minStep,int maxStep,double minResolution, double minStartAngle,bool Pos);
	~TLaser_HOKUYO();


	//===== Input Data ==============
	bool FlagDebug;
	bool FlagBusy;
	int  PkgSize;
	char PkgData[16860];

	//===== Input Function ==============
	void LaserSetup(int, int, int, int, int);
	void LaserSetup(const tsLaserCommand* Cmd);
	const char* Analyze( const unsigned char* DataStream , int Len );

	//===== Seneor Command ==============
	char* MDMS_Command( const tsLaserCommand* Cmd );
	char* QT_Command( void );
	char* RS_Command( void );
	char* BM_Command( void );
	char* VV_Command( void );
	char* PP_Command( void );
	char* II_Command( void );

	//===== Output Function ==============
	tsLaserInfo *Info;

	inline int Command_Length( void ){ return this->Cmd_Len; }

	inline double ResolutionValue( void ){ return Info->Resolution; }
	inline int TimeStampValue( void ){ return this->Time_Stamp; }
	inline int FreqValue( void ){return this->Freq; }
	inline double StatusValue( void ){return this->Status; }
	//===== Output Data ==============

	int minStep,maxStep,frontStep;
	int maxNumber;
	double minResolution, minStartAngle;

private:


	void Base_Command(char C1 , char C2 , int Len);
	const char* ReceiveMDMS( const unsigned char* DataStream , int Len );

	int POW_64[4];

	bool FlagPositive;


	int Time_Stamp;
	int Freq;
	short Status;
	//--MDMS Command Parameter

	char *Command;
	int Cmd_Len;

	int Past_TS;

	const char* Error;
	char Buffer[3];                // ��ƸѽX�Ȧs��
	short Buffer_Size;             // �Y�R�O�� MD �O�ϥ� 3�r���ѽX , MS �O�ϥ� 2�r���ѽX
	short Buffer_Cnt;              // �ѽX�p�ƾ�
	short Byte_Cnt;                // �줸�p�ƾ� ,�C64�줸�h���s�p��
	short Data_Cnt;                // ��ƭp�ƾ� ,�C�ѽX�X�@�����y�u�h�W�[ 1

};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
