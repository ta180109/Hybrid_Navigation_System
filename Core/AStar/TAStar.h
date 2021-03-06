//=============================================
//File name: TAStar
//
//Author   :Hsieh Ming-Hua
//          Transplant form 2012 SKS project
//Phone    :0921307020
//E-mail   :ta180109@hotmail.com
//Update   :2013/07/09
//
//Function :AStar Algotithm and fetch trun point
//===============================================

#ifndef TAStarH
#define TAStarH
#include "../../Database.h"
#include "../../TCoordinate/TCoordinate.h"


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define Def_Open 1
#define Def_Closed 2

using namespace std;
namespace SKS_VC2013
{

	typedef struct
	{
		TCoordinate Pos;
		short Weight;
	}tsNeighbor;

	typedef struct
	{
		vector<tsNeighbor> Neighbor;
		short Status;
		int Weight;
		TCoordinate Father;
		long F,G,H;
	}tsNode;


	class Nodelist {
	public:
		int x,y;
		short Weight;
		Nodelist(int x, int y, short Weight) {
			this->x = x;
			this->y = y;
			this->Weight = Weight;
		}
		inline bool operator < (const Nodelist &rhs) const {
			return Weight < rhs.Weight;
		}
	};

	class NodelistFinder {
	private:
		int Weight;
	public:
		NodelistFinder(const int n):Weight(n) {}
		bool operator ()(const vector<Nodelist>::value_type & value) {
			return value.Weight > this->Weight;
		}
	};


	class TAStar  
	{
	public:
		TAStar();
		~TAStar();

		void AStar_Initialize(void);

		void AStar_Main(void);

		void Behavior_AstarPath( void );
		
	private:

		TCoordinate StartPos, GoalPos;
		bool tmpFlag;
		bool GetTurnPoint;
		bool InPointRange;
		bool FaceTurnPoint;

		TCoordinate NextTurnPoint;
		int TurnPointIndex;
		TCoordinate TmpVector;

		bool CloseState;

		int PathErrRange;

		int AchieveErrRange;

		TCoordinate TargetVector,NextVector;

		TCoordinate VirtualPos;

		//------------Pub--------------

	
		void  AStar_Search( TCoordinate Start , TCoordinate Goal );
		void  AdjustPath( void );
		void  CleanList( void );
		void  LoadGridMap();
		void  FindTurnPoint();

		void OneStepInitial( TCoordinate Start , TCoordinate Goal );
		void OneStepExe();
		unsigned char CurrentStatus;
		unsigned char ObstacleThreshold;

		vector <TCoordinate> SmoothPath;

		//------------Private
		vector < vector<tsNode> > Map;
		void SearchNeighbor( TCoordinate Current );
		void SearchNeighbor_8Connect( TCoordinate Current );
		unsigned int CheckPath_Same( unsigned int PathNum );
		unsigned int CheckPath_Diff( unsigned int PathNum );

		vector<Nodelist> OpenList;
		vector<TCoordinate> ClosedList;

		TCoordinate StartNode,GoalNode;

		int NodeResolution;
	};
}
#endif