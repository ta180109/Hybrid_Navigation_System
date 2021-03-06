#include "TAStar.h"
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace SKS_VC2013;
using namespace std;

#define ACHIVERANGEERR 8
#define TRUNINGWEIGHT 100

TAStar::TAStar()
{
	AStar_Initialize();
	D_Database->NewGridMapFlag = true;
	D_Database->AStarEnable = false;
	tmpFlag = true;
	GetTurnPoint = true;
	FaceTurnPoint = true;
}
TAStar::~TAStar()
{

}

void TAStar::AStar_Initialize(void)
{

	StartNode = aVector(-1,-1);
	GoalNode  = aVector(-1,-1);

	NodeResolution = 10;

	CurrentStatus = 0;
	ObstacleThreshold = 200;

	GoalPos = aVector(-999, -999);

	StartPos= aVector(-999, -999);

	CloseState = false;
	TurnPointIndex =0;

}
//-----------------------------------------------------------------
void TAStar::AStar_Main(void)
{
	if(D_Database->NewGridMapFlag)
		LoadGridMap();
	
	D_Database->AStarPath.StartPos = aVector(D_Database->RobotPos.x,D_Database->RobotPos.y); 
	D_Database->AStarPath.GoalPos = D_Database->EndPosition;


	if(D_Database->AStarEnable) return;
	if( D_Database->AStarPath.StartPos == aVector(-999, -999) ||
		D_Database->AStarPath.StartPos ==  aVector(-999, -999) ) {
			return ;
	}
	if( !(GoalPos  == D_Database->AStarPath.GoalPos) && !(StartPos == D_Database->AStarPath.StartPos) )
	{
		StartPos = D_Database->AStarPath.StartPos;

		GoalPos  = D_Database->AStarPath.GoalPos;

		CleanList();

		AStar_Search( StartPos , GoalPos );

		AdjustPath();

		//D_Database->AStarPath.PCnt = 0;
		
		FindTurnPoint();
		
		Behavior_AstarPath();

	} else {

		Behavior_AstarPath();

	}
}
//-----------------------------------------------------------------
void TAStar::Behavior_AstarPath( void )
{
	int Length = 0;

	if(tmpFlag){
		NextTurnPoint.x = D_Database->TurnPoint[0].x;
		NextTurnPoint.y = D_Database->TurnPoint[0].y;
		tmpFlag = false;
	}
	
	D_Database->GlobaPlanlVector.x = NextTurnPoint.x - D_Database->RobotPos.x;
	D_Database->GlobaPlanlVector.y = NextTurnPoint.y - D_Database->RobotPos.y;
	
	Length = D_Database->GlobaPlanlVector.Length();

	if(Length < ACHIVERANGEERR){ //如果到達轉折點
		InPointRange = true;	
	}else{
		InPointRange = false;
	}

	if(InPointRange){
		TurnPointIndex++;
		if( (TurnPointIndex <= D_Database->TurnPoint.size()-1) && GetTurnPoint){
			NextTurnPoint  = D_Database->TurnPoint[TurnPointIndex]; 
			GetTurnPoint = false;
			FaceTurnPoint = true;
		}
	}else{
		GetTurnPoint = true;
	}
	
	if(FaceTurnPoint){
		
		double AngleRangeError = M_PI * (8.0 / 180.0);
		double MinTurnSpeed = M_PI * (100.0 / 180.0);
	
		TCoordinate TmpVector = NextTurnPoint - D_Database->RobotPos;
		float AngleError = NormalizeAngle(TmpVector.Angle() - D_Database->RobotDir);
	
		if( (fabs(AngleError) > AngleRangeError) || ( (fabs(D_Database->GlobaPlanlVector.Angle()) < 0.000001) && ( fabs(D_Database->RobotDir) < 0.000001)) ){
			D_Database->w = ( AngleError > 0 ) ? MinTurnSpeed  : - MinTurnSpeed;
			D_Database->w *= -1;
			FaceTurnPoint = true;
		}else{
			D_Database->w = 0;
			FaceTurnPoint = false;
		}	
	}else{
		D_Database->w = 0;
		FaceTurnPoint = false;
	}

/*
	int Length = 0;
	int Size = AstarTool::GetInstance()->SmoothPath.size();
	//printf("AStarPath.PCnt %d Size  %d\n",sD_Database->AStarPath.PCnt,Size);
	TCoordinate TmpGoal_V = AstarTool::GetInstance()->SmoothPath[ D_Database->AStarPath.PCnt ] - LocationStatus::Position;

	if( D_Database->AStarPath.PCnt < Size ) {
		Length = TmpGoal_V.Length();
		if(D_Database->AStarPath.PCnt == Size - 1) {
			StrategyStatus::Goal1 = TmpGoal_V >> LocationStatus::Handle;
			if( Length < AchieveErrRange ) {
				D_Database->AStarPath.PCnt++;
				D_Database->AStarPath.Status = StrategyStatus::etAchieve;
			}
		} else {
			if( D_Database->AStarPath.PCnt > 0 ) {
				StrategyStatus::Goal1 = TmpGoal_V >> LocationStatufs::Handle;
				if( Length < PathErrRange ) {
					if( !CloseState ) {
						TargetVector = AstarTool::GetInstance()->SmoothPath[ D_Database->AStarPath.PCnt ] - AstarTool::GetInstance()->SmoothPath[ D_Database->AStarPath.PCnt-1 ];
						NextVector = AstarTool::GetInstance()->SmoothPath[ D_Database->AStarPath.PCnt+1 ] - AstarTool::GetInstance()->SmoothPath[ D_Database->AStarPath.PCnt ];
						VirtualPos = LocationStatus::Position +(( TmpGoal_V.UnitVector() ) * (Length+10));
						CloseState = true;
					}
					if( Length < PathErrRange  ) StrategyStatus::FixSpeed = 60;
					StrategyStatus::Goal1 =(VirtualPos - LocationStatus::Position) >> LocationStatus::Handle;
					if( NextVector.cross(TargetVector) * NextVector.cross( TmpGoal_V ) < 0 || Length < 10 ) {
						D_Database->AStarPath.PCnt++;
						CloseState = false;
					}

				}
			} else {
				StrategyStatus::Goal1 = TmpGoal_V >> LocationStatus::Handle;
				if( Length < PathErrRange ) {
					D_Database->AStarPath.PCnt++;
				}
			}

		}
		D_Database->AStarPath.Status = StrategyStatus::etMotion;
	} else {
		D_Database->AStarPath.Status = StrategyStatus::etAchieve;
		StrategyStatus::Goal1 = aVector(0,0);
	}

	*/
}

void TAStar::CleanList( void )
{
	D_Database->Path.clear();
	ClosedList.clear();
	OpenList.clear();
}
//--------------------------xmlGridMap

void TAStar::LoadGridMap() {
	Map.clear();
	vector<tsNode> vecTmp;
	tsNode tsNodeTmp;
	int i=0,j=0;
	while(i<=59){
		tsNodeTmp.Weight = D_Database->MapWeight[i][j++];
		vecTmp.push_back(tsNodeTmp);
		if(j>59){
			i++;
			j=0;
			Map.push_back(vecTmp);
			vecTmp.clear();
		}
	}

	D_Database->NewGridMapFlag = false;
}

//---------------------------------------------------------------------------
void TAStar::AStar_Search( TCoordinate Start , TCoordinate Goal )
{
	CurrentStatus %=255;

	CurrentStatus +=5;

	TCoordinate Front,Father;
	//---- record the start and goal -----
	StartNode.x = (int)(Start.x/NodeResolution);
	StartNode.y = (int)(Start.y/NodeResolution);
	GoalNode.x  = (int)(Goal.x /NodeResolution);
	GoalNode.y  = (int)(Goal.y /NodeResolution);

	//---- initial the list information
	Map[StartNode.x][StartNode.y].Father = StartNode;
	Map[StartNode.x][StartNode.y].G = 0;
//	Map[StartNode.x][StartNode.y].H = NodeResolution*(( GoalNode - StartNode ).Length());

	
	Map[StartNode.x][StartNode.y].H = NodeResolution*( fabs(GoalNode.x - StartNode.x) + fabs(GoalNode.y - StartNode.y) );

	Map[StartNode.x][StartNode.y].F = Map[StartNode.x][StartNode.y].G + Map[StartNode.x][StartNode.y].H;

	OpenList.push_back(Nodelist(StartNode.x,StartNode.y,Map[StartNode.x][StartNode.y].Weight));
	//---- execute the A Star
	Front.x = OpenList.begin()->x;
	Front.y = OpenList.begin()->y;

	//--------------------------------------------------------------------------
	//-------------- Stop Condition --------------------------------------------
	//--------------------------------------------------------------------------
	while( (Front.x != -1        || Front.y != -1) &&
		(Front.x != GoalNode.x || Front.y != GoalNode.y) )
	{
				OpenList.erase(OpenList.begin());

		Map[Front.x][Front.y].Status = CurrentStatus-Def_Closed;
		ClosedList.push_back( Front );
		SearchNeighbor_8Connect( Front );

		Front.x = OpenList.begin()->x;
		Front.y = OpenList.begin()->y;

	}
	//--------------------------------------------------------------------------
	//-------------- Return Path Info ------------------------------------------
	//--------------------------------------------------------------------------

	if( Front.x == GoalNode.x && Front.y == GoalNode.y )
	{
		D_Database->Path.insert( D_Database->Path.begin(), Goal );
		Father = GoalNode;
		while( StartNode.x != Father.x || StartNode.y != Father.y   )
		{
			Father = Map[ Father.x ][ Father.y ].Father;
			
			if(StartNode.x == Father.x && StartNode.y == Father.y){
				
				D_Database->Path.insert( D_Database->Path.begin(), Start);
			}else{
				D_Database->Path.insert( D_Database->Path.begin(), (Father*NodeResolution)+ aVector(NodeResolution/2,NodeResolution/2) );
				
			}
		}
	}
}
//---------------------------------------------------------------------------
void TAStar::SearchNeighbor_8Connect( TCoordinate Current )
{
	TCoordinate TmpPos;
	int TmpWeight;

	for( int i = -1; i < 2; i++ )
	{
		for( int j = -1; j < 2; j++ )
		{
			if( i==0 && j==0 ) continue;

			TmpPos = Current + aVector( i, j );
			if( TmpPos.x < 0 || TmpPos.y < 0 || TmpPos.x >= Map[0].size() ||TmpPos.y >= Map.size() ) continue;

			TmpWeight = Map[TmpPos.x][TmpPos.y].Weight;

			if( TmpWeight < ObstacleThreshold  )
			{
				if( i*j==0 ) {      // if neighbor is diagonal, then G is 1a4.
					TmpWeight += NodeResolution;
				} else {
					if( Map[TmpPos.x][Current.y].Weight > ObstacleThreshold ||
						Map[Current.x][TmpPos.y].Weight > ObstacleThreshold ) continue;
					TmpWeight += 1.4*NodeResolution;
				}
				if( Map[TmpPos.x][TmpPos.y].Status == CurrentStatus-Def_Open)
				{
					if( Map[ TmpPos.x ][ TmpPos.y ].G > Map[Current.x][Current.y].G + TmpWeight )
					{
						Map[TmpPos.x][TmpPos.y].Father = Current;
						Map[TmpPos.x][TmpPos.y].G =  Map[Current.x][Current.y].G + TmpWeight;
						Map[TmpPos.x][TmpPos.y].F = Map[TmpPos.x][TmpPos.y].G + Map[TmpPos.x][TmpPos.y].H;

						vector<Nodelist>::iterator it = find_if(OpenList.begin(),OpenList.end(),NodelistFinder(Map[TmpPos.x][TmpPos.y].F));
						OpenList.insert(it, Nodelist(TmpPos.x,TmpPos.y ,Map[TmpPos.x][TmpPos.y].F));
					}
				}
				else if( Map[TmpPos.x][TmpPos.y].Status != CurrentStatus-Def_Closed )
				{
					Map[TmpPos.x][TmpPos.y].Status = CurrentStatus-Def_Open;
					Map[TmpPos.x][TmpPos.y].Father = Current;
					Map[TmpPos.x][TmpPos.y].G = Map[Current.x][Current.y].G + TmpWeight;
					Map[TmpPos.x][TmpPos.y].H = NodeResolution*((GoalNode - TmpPos).Length());

					//Map[TmpPos.x][TmpPos.y].H = NodeResolution*( fabs(GoalNode.x - TmpPos.x) + fabs(GoalNode.y - TmpPos.y) );
					Map[TmpPos.x][TmpPos.y].F = Map[TmpPos.x][TmpPos.y].G + Map[TmpPos.x][TmpPos.y].H;

					vector<Nodelist>::iterator it = find_if(OpenList.begin(),OpenList.end(),NodelistFinder(Map[TmpPos.x][TmpPos.y].F));
					OpenList.insert(it, Nodelist(TmpPos.x,TmpPos.y ,Map[TmpPos.x][TmpPos.y].F));
				}
			}
		}
	}
}
void TAStar::AdjustPath( void )
{
	unsigned int tmp1,tmp2;

	if( D_Database->Path.size() > 3 )
	{
		SmoothPath.clear();
		SmoothPath.push_back(D_Database->Path.front());
		for(unsigned int i=2; i< D_Database->Path.size()-1 ; i++)
		{
			tmp1 = CheckPath_Same( i );
			if( tmp1 == i )
			{
				tmp2 = CheckPath_Diff(i+1);
				i = ( tmp2 - i > 1 )? tmp2 : tmp1;
			}
			else
			{
				i = tmp1;
			}
			SmoothPath.push_back( D_Database->Path[i] );
		}
	}
	else
	{
		SmoothPath = D_Database->Path ;
	}
}
//---------------------------------------------------------------------------
unsigned int TAStar::CheckPath_Diff( unsigned int PathNum )
{
	if( PathNum == D_Database->Path.size()-2 ) return D_Database->Path.size()-1;
	TCoordinate Vector1 = D_Database->Path[PathNum-1] - D_Database->Path[PathNum-2];
	TCoordinate Vector2 = D_Database->Path[PathNum] - D_Database->Path[PathNum-1];
	TCoordinate Vector3 = D_Database->Path[PathNum+1] - D_Database->Path[PathNum];
	if( Vector3 == Vector2 )
		if( (Vector1.x != Vector3.x) || (Vector1.y != Vector3.y) )
			return PathNum-1;
		else
			return PathNum;
	else
		return CheckPath_Diff( PathNum+1 );
}
//---------------------------------------------------------------------------
unsigned int TAStar::CheckPath_Same( unsigned int PathNum )
{
	if( PathNum == D_Database->Path.size()-2 ) return D_Database->Path.size()-1;

	TCoordinate Vector1 = D_Database->Path[PathNum] - D_Database->Path[PathNum-1];
	TCoordinate Vector2 = D_Database->Path[PathNum+1] - D_Database->Path[PathNum];
	if( Vector1 == Vector2 )
		return CheckPath_Same( PathNum+1 );
	else
		return PathNum;
}



void TAStar::FindTurnPoint(){
		TCoordinate PosFirst,PosMiddle,PosLast;
		double GradientFirst,GradientLast;

		for(int i=2;i< SmoothPath.size();i++){
			PosFirst = SmoothPath[i-2];
			PosMiddle = SmoothPath[i-1];
			PosLast = SmoothPath[i];

			GradientFirst = (PosMiddle.y - PosFirst.y) / ((PosMiddle.x - PosFirst.x) + DBL_MIN_10_EXP) ;
			GradientLast = (PosLast.y - PosMiddle.y) / ((PosLast.x - PosMiddle.x) + DBL_MIN_10_EXP);

			if (GradientFirst != GradientLast)
				D_Database->TurnPoint.insert( D_Database->TurnPoint.end(), PosMiddle);
		}

		D_Database->TurnPoint.insert( D_Database->TurnPoint.end(), D_Database->EndPosition);
//   		char filename[]="test.txt";
//  	  		fstream fp;
//  	  		fp.open(filename, ios::out);//開啟檔案
//  	  		 
//  	  		for(int i=0;i<D_Database->TurnPoint.size();i++){
//  	  		 		fp<< D_Database->TurnPoint[i].x <<","<<D_Database->TurnPoint[i].y  <<endl;
//  	  		 }
//  	  		 fp.close();//關閉檔案
 	
}