#include "TAStar.h"
#include <algorithm>

using namespace SKS_VC2013;
using namespace std;

//Stra_AStar* Stra_AStar::m_UniqueInstance = new Stra_AStar();

TAStar::TAStar()
{

}

TAStar::~TAStar()
{

}
//-----------------------------------------------------------------
// int Stra_AStar::LoadXMLSettings(TiXmlElement* element) {
// 	if(element != NULL) {
// 		element->Attribute("PathErrRange", &PathErrRange);
// 		element->Attribute("AchieveErrRange", &AchieveErrRange);
// 	}
// }
//-----------------------------------------------------------------
void TAStar::Initialize(void)
{

	StartNode = aVector(-1,-1);
	GoalNode  = aVector(-1,-1);

	NodeResolution = 10;

	CurrentStatus = 0;
	ObstacleThreshold = 200;

	GoalPos = aVector(-999, -999);

	StartPos= aVector(-999, -999);

	CloseState = false;

}
//-----------------------------------------------------------------
void TAStar::Process(void)
{
	//if(!StrategyStatus::AStarEnable) return;
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

		D_Database->AStarPath.PCnt = 0;

		Behavior_AstarPath();

	} else {

		Behavior_AstarPath();

	}
}
//-----------------------------------------------------------------
void TAStar::Behavior_AstarPath( void )
{
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
				StrategyStatus::Goal1 = TmpGoal_V >> LocationStatus::Handle;
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
	Path.clear();
	ClosedList.clear();
	OpenList.clear();
}
//--------------------------xmlGridMap
/*
int AstarTool::LoadXMLSettings(TiXmlElement* element) {
	Map.clear();
	if(element != NULL) {
		TiXmlElement* child=element->FirstChildElement();
		while(child!=NULL) {
			vector<tsNode> vecTmp;
			TiXmlAttribute* type=child->FirstAttribute();
			while(type!=NULL) {
				tsNode tsNodeTmp;
				tsNodeTmp.Weight = atoi(type->Value());
				vecTmp.push_back(tsNodeTmp);
				type=type->Next();
			}
			Map.push_back(vecTmp);
			child=child->NextSiblingElement();
		}
	}
	//	for(int i =59; i>=0; i--){
	//		for(int j=59; j>=0; j--){
	//			if(Map[i][j].Weight == 255) printf("X");
	//			if(Map[i][j].Weight == 128) printf("b");
	//			if(Map[i][j].Weight == 0) printf(" ");
	//			if(j==0) printf("\n");
	//
	//		}
	//	}

	return 0;
}
*/
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

	//printf("StartNode %f %f\n",StartNode.x,StartNode.y);
	//printf("GoalNode %f %f\n",GoalNode.x,GoalNode.y);

	//---- initial the list information
	Map[StartNode.x][StartNode.y].Father = StartNode;
	Map[StartNode.x][StartNode.y].G = 0;
	Map[StartNode.x][StartNode.y].H = NodeResolution*(( GoalNode - StartNode ).Length());
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
		//OpenList.extract_min();

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
		Path.insert( Path.begin(), Goal );
		Father = GoalNode;
		while( StartNode.x != Father.x || StartNode.y != Father.y   )
		{
			Father = Map[ Father.x ][ Father.y ].Father;
			if(StartNode.x == Father.x && StartNode.y == Father.y)
				Path.insert( Path.begin(), Start );
			else
				Path.insert( Path.begin(), (Father*NodeResolution)+ aVector(NodeResolution/2,NodeResolution/2) );
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
						Map[TmpPos.x][TmpPos.y].G = Map[Current.x][Current.y].G + TmpWeight;
						Map[TmpPos.x][TmpPos.y].F = Map[TmpPos.x][TmpPos.y].G + Map[TmpPos.x][TmpPos.y].H;

						vector<Nodelist>::iterator it = find_if(OpenList.begin(),OpenList.end(),NodelistFinder(Map[TmpPos.x][TmpPos.y].F));
						OpenList.insert(it, Nodelist(TmpPos.x,TmpPos.y ,Map[TmpPos.x][TmpPos.y].F));
						//OpenList.push_back(Nodelist(TmpPos.x,TmpPos.y ,Map[TmpPos.x][TmpPos.y].F) );
						//sort(OpenList.begin(),OpenList.end());
					}
				}
				else if( Map[TmpPos.x][TmpPos.y].Status != CurrentStatus-Def_Closed )
				{
					Map[TmpPos.x][TmpPos.y].Status = CurrentStatus-Def_Open;
					Map[TmpPos.x][TmpPos.y].Father = Current;
					Map[TmpPos.x][TmpPos.y].G = Map[Current.x][Current.y].G + TmpWeight;
					Map[TmpPos.x][TmpPos.y].H = NodeResolution*((GoalNode - TmpPos).Length());
					Map[TmpPos.x][TmpPos.y].F = Map[TmpPos.x][TmpPos.y].G + Map[TmpPos.x][TmpPos.y].H;

					vector<Nodelist>::iterator it = find_if(OpenList.begin(),OpenList.end(),NodelistFinder(Map[TmpPos.x][TmpPos.y].F));
					OpenList.insert(it, Nodelist(TmpPos.x,TmpPos.y ,Map[TmpPos.x][TmpPos.y].F));

					//OpenList.push_back(Nodelist(TmpPos.x, TmpPos.y,Map[TmpPos.x][TmpPos.y].F) );
					//sort(OpenList.begin(),OpenList.end());
				}
				//printf("G: %d ",Map[TmpPos.x][TmpPos.y].G );
				//printf("H: %d ",Map[TmpPos.x][TmpPos.y].H );
			}
		}
	}
	//printf("\n");
}
void TAStar::AdjustPath( void )
{
	unsigned int tmp1,tmp2;

	if( Path.size() > 3 )
	{
		SmoothPath.clear();
		SmoothPath.push_back(Path.front());
		for(unsigned int i=2; i< Path.size()-1 ; i++)
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
			SmoothPath.push_back( Path[i] );
		}
	}
	else
	{
		SmoothPath = Path ;
	}
}
//---------------------------------------------------------------------------
unsigned int TAStar::CheckPath_Diff( unsigned int PathNum )
{
	if( PathNum == Path.size()-2 ) return Path.size()-1;
	TCoordinate Vector1 = Path[PathNum-1] - Path[PathNum-2];
	TCoordinate Vector2 = Path[PathNum] - Path[PathNum-1];
	TCoordinate Vector3 = Path[PathNum+1] - Path[PathNum];
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
	if( PathNum == Path.size()-2 ) return Path.size()-1;

	TCoordinate Vector1 = Path[PathNum] - Path[PathNum-1];
	TCoordinate Vector2 = Path[PathNum+1] - Path[PathNum];
	if( Vector1 == Vector2 )
		return CheckPath_Same( PathNum+1 );
	else
		return PathNum;
}