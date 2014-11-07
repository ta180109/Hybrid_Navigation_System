#ifndef DatabaseH
#define DatabaseH

#include <string>
#include <vector>
#include "TCoordinate/TCoordinate.h"


#define Radar_Width 144				//!�p�F�ϼe��
#define Radar_Height 144			//!�p�F�Ϫ���
#define Map_Width 600
#define Map_Height 600
#define Laser_Width 500
#define Laser_Height 500
#define LASER_SCAN_NUM 73

const double RaderCenter_x = 72;		//!�p�F���� x
const double RaderCenter_y = 72;		//!�p�F���� y
const double Rader_Radius = 70;				//!�p�F�b�| = 70
const double PI = 3.14159265358979323846;

const double LaserCenter_x = 250;
const double LaserCenter_y = 250;

class data1
{
	public:		// User declarations
		double X;			//!�����H��X�y��
		double Y;			//!�����H��Y�y��
		double X_tar;
		double Y_tar;
		double Angle;
		double R;
		double Wheel;
};
extern data1 *D_Robot;		//�����H

class data2
{
	public:		// User declarations
		double X;			//���X��V
		double Y;			//���Y��V
		double Radian;		//�������
		double Camera;
		double TakeBall;
};
extern data2 *D_Order;		//���O(����)

class data3
{
	public:		// User declarations
		double X;			//�ƹ��I���y�� x
		double Y;			//�ƹ��I���y�� y
		double Length;		//�ƹ��I������ߪ���
		double Angle;		//�ƹ��I������ߨ���
		double Radian;		//�ƹ��I������ߩ���
};
extern data3 *D_Touch;		//�p�F�ާ@

class data4
{
	public:
		double X;
		double Y;
		int Touch;
		int Right;
};
extern data4 *D_mos;		//�ƹ��ާ@

class data5
{
	public:		// User declarations
		double X;			//���X��V
		double Y;			//���Y��V
		double Radian;		//�������
};
extern data5 *D_Vector;		//�V�q(�ǰe)

class data6
{
	public:		// User declarations
		int Minute;			//���X��V
		int Second;			//���Y��V
};
extern data6 *D_Time;		//�V�q(�ǰe)

class data7
{
	public:		// User declarations
		int Angle;			//���X��V
		int Spa;			//���Y��V
};
extern data7 *D_Range;		//�V�q(�ǰe)

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
extern data10 *R_Robot;		//�^�Ǫ������H�V�q(����)


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
