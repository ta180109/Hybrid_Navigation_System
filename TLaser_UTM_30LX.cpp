//---------------------------------------------------------------------------


#pragma hdrstop

#include "StdAfx.h"

#include <math.h>
#include <stdlib.h>


#include "TLaser_UTM_30LX.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int C4_Decoding( const char& C1,const char& C2,const char& C3,const char& C4)
{
	return  ( ((C1-0x30) & 0x3f) *262144 +
		((C2-0x30) & 0x3f) *4096 +
		((C3-0x30) & 0x3f) *64 +
		((C4-0x30) & 0x3f)  )&0x00ffffff;
}
//---------------------------------------------------------------------------
int C3_Decoding( const char& C1,const char& C2,const char& C3 )
{
	return  ( ((C1-0x30) & 0x3f) *4096 +
		((C2-0x30) & 0x3f) *64 +
		((C3-0x30) & 0x3f)  )&0x0003ffff;
}
//---------------------------------------------------------------------------
int C2_Decoding( const char& C1,const char& C2 )
{
	return  ( ((C1-0x30) & 0x3f) *64 +
		((C2-0x30) & 0x3f)  )&0x00000fff;
}
//---------------------------------------------------------------------------
//===========================================================================
TLaser_HOKUYO::TLaser_HOKUYO(int minStep,int maxStep,double minResolution, double minStartAngle,bool Pos)
{
	for(int i = 0 ;i < 4 ; i++ ){ POW_64[i] = (int) pow(64.0 ,i); }

	//-----------------------------------------
	this->minStep = minStep;
	this->maxStep = maxStep;
	this->frontStep = (maxStep-minStep)/2;
	this->maxNumber = (maxStep-minStep)+1;
	this->minResolution = minResolution;
	this->minStartAngle = minStartAngle;

	this->FlagPositive = Pos;

	//-----------------------------------------
	Info = new tsLaserInfo;

	Info->Data  = new int[this->maxNumber];
	for (int i=0;i<this->maxNumber;i++){Info->Data[i]=0;}
	Info->Angle = new double[this->maxNumber];
	//-----------------------------------------
	LaserSetup(minStep,maxStep,1,0,0);


	FlagDebug = false;
	FlagBusy  = false;
	Past_TS = 1;
	Freq    = 0;
	PkgSize = 0;
}
//---------------------------------------------------------------------------
TLaser_HOKUYO::~TLaser_HOKUYO()
{
	delete []Info->Angle;
	delete []Info->Data;
}
//---------------------------------------------------------------------------
void TLaser_HOKUYO::LaserSetup( int iStart, int iEnd, int iCluster, int iInterval, int iTimes)
{
	Info->FlagRenew = false;

	iCluster = (iCluster > 1 ) ? iCluster : 1;
	Info->Number = ( ( iEnd - iStart ) / iCluster ) + 1;      //掃描線數量

	Info->Resolution = iCluster * this->minResolution;
	if (FlagPositive)
	{
		Info->RightBorder = ( iStart - this->frontStep)* this->minResolution;
		Info->LiftBorder  = ( iEnd - this->frontStep  )* this->minResolution;
	} 
	else
	{
		Info->RightBorder = -1*( iEnd - this->frontStep  )* this->minResolution;
		Info->LiftBorder  = -1*( iStart - this->frontStep)* this->minResolution;
	}
	Info->StartAngle = Info->RightBorder + Info->Resolution / 2.0;

	Info->Angle[0] = Info->StartAngle;
	for( int i = 1; i < Info->Number; i++ ) Info->Angle[i] = Info->Angle[i-1] + Info->Resolution;
}
//---------------------------------------------------------------------------
void TLaser_HOKUYO::LaserSetup(const tsLaserCommand* Cmd)
{
	LaserSetup(Cmd->Start,Cmd->End,Cmd->Cluster,Cmd->Interval,Cmd->NumOfScans);
}
//---------------------------------------------------------------------------
void TLaser_HOKUYO::Base_Command(char C1 , char C2 , int Len)
{
	this->Cmd_Len = Len;
	this->Command = new char[ this->Cmd_Len ];                //宣告新的命令矩陣

	this->Command[0] = C1;  this->Command[1] = C2;                //填入命令編號
	this->Command[ this->Cmd_Len-1 ] = defNewLine;                //最後一筆為 LF
}
//---------------------------------------------------------------------------
char* TLaser_HOKUYO::MDMS_Command( const tsLaserCommand* Cmd )
{

	//===== 設定基本命令格式 ================================================
	this->Base_Command( 'M' ,'D' ,16 );

	LaserSetup(Cmd->Start,Cmd->End,Cmd->Cluster,Cmd->Interval,Cmd->NumOfScans);

	int Data_len = Info->Number * 3;
	PkgSize = Data_len + 29 + 2*( (int)( Data_len )/64 );
	//===== 命令參數轉成封包格式 =============================================
	int StartTmp = Cmd->Start;
	int EndTmp   = Cmd->End;

	for( int r = 5 ; r >= 2 ; r-- )
	{
		this->Command[ r ] = LaserEncoding( (char)( StartTmp % 10) );
		StartTmp = StartTmp / 10;
	}
	for( int r = 9 ; r >= 6 ; r-- )
	{
		this->Command[ r ] = LaserEncoding( (char)( EndTmp % 10) );
		EndTmp   = EndTmp / 10;
	}
	this->Command[10] = LaserEncoding( (char)( Cmd->Cluster / 10) );
	this->Command[11] = LaserEncoding( (char)( Cmd->Cluster % 10) );

	this->Command[12] = LaserEncoding( (char) Cmd->Interval );

	this->Command[13] = LaserEncoding( (char)( Cmd->NumOfScans / 10) );
	this->Command[14] = LaserEncoding( (char)( Cmd->NumOfScans % 10) );

	return this->Command;
}

//---------------------------------------------------------------------------
char* TLaser_HOKUYO::QT_Command( void )
{
	Freq = 0;
	this->Base_Command( 'Q' ,'T' ,3 );return this->Command;
}
//---------------------------------------------------------------------------
char* TLaser_HOKUYO::RS_Command( void )
{
	Freq = 0;
	this->Base_Command( 'R' ,'S' ,3 );return this->Command;
}
//---------------------------------------------------------------------------
char* TLaser_HOKUYO::BM_Command( void )
{
	this->Base_Command( 'B' ,'M' ,3 );return this->Command;
}
//---------------------------------------------------------------------------
char* TLaser_HOKUYO::VV_Command( void )
{
	this->Base_Command( 'V' ,'V' ,3 );return this->Command;
}
//---------------------------------------------------------------------------
char* TLaser_HOKUYO::PP_Command( void )
{
	this->Base_Command( 'P' ,'P' ,3 );return this->Command;
}
//---------------------------------------------------------------------------
char* TLaser_HOKUYO::II_Command( void )
{
	this->Base_Command( 'I' ,'I' ,3 );return this->Command;
}
//---------------------------------------------------------------------------
const char* TLaser_HOKUYO::Analyze( const unsigned char* DataStream , int Len )
{
	Error = NULL;
	Freq = 0;
	switch( DataStream[0] )
	{
	case 'M': if( DataStream[1]=='D' || DataStream[1]=='S' ){ Error = ReceiveMDMS( DataStream ,Len ); break;}
	case 'G': if( DataStream[1]=='D' || DataStream[1]=='S' ){ Error = "GDGS-Command"; break; }
	case 'B': if( DataStream[1]=='M' ) { Error = "BM-Command"; break; }
	case 'Q': if( DataStream[1]=='T' ) { Error = "QT-Command"; break; }
	case 'R': if( DataStream[1]=='S' ) { Error = "RS-Command"; break; }
	case 'T': if( DataStream[1]=='M' ) { Error = "TM-Command"; break; }
	case 'S': if( DataStream[1]=='S' ) { Error = "SS-Command"; break; }
	case 'D': if( DataStream[1]=='B' ) { Error = "DB-Command"; break; }
	case 'V': if( DataStream[1]=='V' ) { Error = "VV-Command"; break; }
	case 'P': if( DataStream[1]=='P' ) { Error = "PP-Command"; break; }
	case 'I': if( DataStream[1]=='I' ) { Error = "II-Command"; break; }
	default:
		Error = "Unknown Data";
	}
	return Error;
}
//---------------------------------------------------------------------------
const char* TLaser_HOKUYO::ReceiveMDMS( const unsigned char* DataStream , int Len )
{

	if( FlagDebug )
	{
		for(int i = 0; i < Len ; i++){ PkgData[i] = DataStream[i]; }
	}
	// 資料解碼暫存器
	Buffer[0] = 0;  Buffer[1] = 0; Buffer[2] = 0;
	Buffer_Size = DataStream[1]=='D' ? 3 : 2;               // 若命令為 MD 是使用 3字元解碼 , MS 是使用 2字元解碼
	Buffer_Cnt = 0;                                         // 解碼計數器
	Byte_Cnt = 0;                                           // 位元計數器 ,每64位元則重新計數
	Data_Cnt = 0;                                           // 資料計數器 ,每解碼出一條掃描線則增加 1

	Status = LaserDecoding( DataStream[16] )*10 + LaserDecoding( DataStream[17] );
	switch( Status ){
	case  0: return "Command received without any Error";
	case  1: return "Starting Step has non-numeric value";
	case  2: return "End Step has non-numeric value";
	case  3: return "Cluster Count has non-numeric value";
	case  4: return "End Step is out of range";
	case  5: return "End Step is smaller than Starting Step";
	case  6: return "Scan Interval has non-numeric value";
	case  7: return "Number of Scan has non-numeric value";
	case 98: return "Resumption of process after confirming normal laser operation";
	case 99:

		//==== 第20~23筆為 時間標記
		Time_Stamp = C4_Decoding( DataStream[20],DataStream[21],DataStream[22],DataStream[23] );
		Freq = ((Time_Stamp - Past_TS) == 0 )? 0 : 1000 / (Time_Stamp - Past_TS);
		Past_TS = Time_Stamp;
		//==== 第24筆為 CheckSum
		//==== 第25筆為 LF
		//==== 第26筆之後 到 倒數第3筆之前 為掃描線資料，倒數第三筆為 Checksum 倒數兩筆為 LF LF
		for( int i = 26 ; i < PkgSize - 3 ; i++ )
		{

			//=== 若掃描線資料超過 64 byte ，則每 64 byte 夾帶一筆 Checksum 與 LF
			if( Byte_Cnt < 64 )
			{

				Buffer[Buffer_Cnt] = DataStream[i];
				//=== 解碼長度足夠，將資料存入資料矩陣
				if( ++Buffer_Cnt >= Buffer_Size  )
				{
					if (this->FlagPositive)
					{
						Info->Data[ Data_Cnt++ ] = C3_Decoding( Buffer[0] ,Buffer[1] ,Buffer[2] )/ def_LaserScale;
					} 
					else
					{
						Info->Data[ (Info->Number-1) - Data_Cnt++ ] = C3_Decoding( Buffer[0] ,Buffer[1] ,Buffer[2] )/ def_LaserScale;
					}

					Buffer_Cnt = 0;
				}
				Byte_Cnt++;
			}
			else
			{
				Byte_Cnt = 0;
				i++;
			}
		}
		Info->FlagRenew = true;
		return "OK MDMS";

	default:
		if( Status >= 21 && Status <= 49 )
		{
			return "Processing stopped to verify the error";
		}
		else if( Status >= 50 && Status <= 97 )
		{
			return "Hardware trouble (such as laser, motor malfunctions etc)";
		}
		else
		{
			return "Unknown Status";
		}
	}
}

