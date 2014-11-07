#ifndef DatabaseH
#define DatabaseH

#include <string>
#include <vector>
#include "TCoordinate/TCoordinate.h"


#define Radar_Width 144				//!雷達圖寬度
#define Radar_Height 144			//!雷達圖長度
#define Map_Width 600
#define Map_Height 600
#define Laser_Width 500
#define Laser_Height 500
#define LASER_SCAN_NUM 73

const double RaderCenter_x = 72;		//!雷達中心 x
const double RaderCenter_y = 72;		//!雷達中心 y
const double Rader_Radius = 70;				//!雷達半徑 = 70
const double PI = 3.14159265358979323846;

const double LaserCenter_x = 250;
const double LaserCenter_y = 250;

class data1
{
	public:		// User declarations
		double X;			//!機器人的X座標
		double Y;			//!機器人的Y座標
		double X_tar;
		double Y_tar;
		double Angle;
		double R;
		double Wheel;
};
extern data1 *D_Robot;		//機器人

class data2
{
	public:		// User declarations
		double X;			//控制的X方向
		double Y;			//控制的Y方向
		double Radian;		//控制的弧度
		double Camera;
		double TakeBall;
};
extern data2 *D_Order;		//指令(控制)

class data3
{
	public:		// User declarations
		double X;			//滑鼠點擊座標 x
		double Y;			//滑鼠點擊座標 y
		double Length;		//滑鼠點擊離圓心長度
		double Angle;		//滑鼠點擊離圓心角度
		double Radian;		//滑鼠點擊離圓心弧度
};
extern data3 *D_Touch;		//雷達操作

class data4
{
	public:
		double X;
		double Y;
		int Touch;
		int Right;
};
extern data4 *D_mos;		//滑鼠操作

class data5
{
	public:		// User declarations
		double X;			//控制的X方向
		double Y;			//控制的Y方向
		double Radian;		//控制的弧度
};
extern data5 *D_Vector;		//向量(傳送)

class data6
{
	public:		// User declarations
		int Minute;			//控制的X方向
		int Second;			//控制的Y方向
};
extern data6 *D_Time;		//向量(傳送)

class data7
{
	public:		// User declarations
		int Angle;			//控制的X方向
		int Spa;			//控制的Y方向
};
extern data7 *D_Range;		//向量(傳送)

struct Furniture_site
{
	int x;
	int y;
	int Width;
	int Height;
	int Angle;
};

class data8
{
	public:		// User declarations
		struct 
		{
			Furniture_site Sofa;
			Furniture_site Table;
			Furniture_site Cabinet;
		}M_LivingRM;
		struct 
		{
			Furniture_site Table;
			Furniture_site Chair;
			Furniture_site door;
		}M_DiningRM;
		struct 
		{
			Furniture_site Desk;
			Furniture_site Chair;
			Furniture_site Cabinet;
		}M_Library;
		
		struct 
		{
			Furniture_site Bed;
			Furniture_site door;
		}M_BedRM;

		Furniture_site M_Trashcan;
		Furniture_site M_ChargeArea;
		Furniture_site M_EndArea;
};
extern data8 *D_Furniture;

struct Laser_information
{
	double Angle;
	double Distance;
};
extern Laser_information *Real_Laser;
extern Laser_information *Sim_Laser;


class data9
{
	public:		
		double x;
		double y;
		double ang;
};
extern data9 *R_Position;

class data10
{
	public:
		double X;
		double Y;
		double Radian;
		double Camera_Angle;
};
extern data10 *R_Robot;		//回傳的機器人向量(控制)


class Database{
	private:

	public:

		 double x;
		 double y;
		 double w;
		 double FI;

		 double Direction;

		 TCoordinate StartPosition;
		 TCoordinate EscapePosition;
		 TCoordinate EndPosition;
		 TCoordinate RobotPos;
		
		 bool FlagForward;

		 //for AStar
		 //bool AStarEnable;

		 struct {
			 int Status;
			 TCoordinate StartPos;
			 TCoordinate GoalPos;
			 int PCnt;
		 }AStarPath;

		//for velocity control
		 float FixSpeed;                                 // Speed Power 1~100 %
		 double MotionDistance;
		 double MotionAngle;
		 TCoordinate PathMotion;
		 float PathRotation;


		 long MotorSpeed[3];

};
extern Database *D_Database;	

void Robot_Request(System::String^ Re_Node);

#endif
