#include "ChessBoard.h"

/*
//defaulting to standard 8 sided chess board 

*/

ChessBoard::ChessBoard()
{
	vector<Travail> vTravails;
	ChessBoard::visitedBoard[8][8];// = { 0 };//set all to false
	memset(visitedBoard, 0, sizeof(visitedBoard[0][0]) * 8 * 8);
    bool flag = false; //set to true when end is found

};

void ChessBoard::RunBreadthFirstSearch(Position *posStart, Position *posEnd)
{

	ChessPiece KnightPiece;
    int iD = 0;
	int prevId = -1;//set up the first Travail with starting position
	struct Travail startTravail;
	startTravail.travailPos = posStart;
	startTravail.prevPos = posStart;
	vTravails.push_back(startTravail);
	flag = false;
	vector<Position*> *vDepthPositions = new vector<Position*>;
	//run the system once in order to initialise the vector vDepthPosiitons
    for(int l = 0; l < 8; ++l)
    {
		if (SearchByMove(KnightPiece, l + 1, &vTravails, posStart, posEnd, *vDepthPositions))
		{
			flag = true;
			break;
		}
	}

    while(!flag)
    {
		//loop the vector positions. for each vector depth position, run its 8 possible moves for each position at that depth
		vector<Position*> *vNextDepthPositions = new vector<Position*>;
		int i = 0;
		for(vector<Position*>::iterator it = vDepthPositions->begin(); it != vDepthPositions->end(); ++it) {
			Position* posStar = vDepthPositions->at(i);
			i++;
			for(int l = 0; l < 8; ++l)
			{
				if (SearchByMove(KnightPiece, l + 1, &vTravails, posStar, posEnd, *vNextDepthPositions))
				{
					flag = true;
					break;
				}
			}
			if (flag == true)
				break;
		}
		vDepthPositions->clear();
		vDepthPositions = vNextDepthPositions;
	}

};

bool ChessBoard::SearchByMove(ChessPiece KnightPiece, int iMove, vector<Travail>* vTravails, Position* posStart, Position* posEnd, vector<Position*> &vDepthPosiitons )
{
	Position* posTemp = new Position();
    *posTemp = *posStart;
	struct ChessPiece::KnightMove knightMove = KnightPiece.GetKnightMove(iMove);
	if (posTemp->IsMoveValid(knightMove.iColumnMove, knightMove.iRowMove))
	{
		posTemp->MovePosition(knightMove.iColumnMove, knightMove.iRowMove);
		int iMovedColumn = posTemp->GetiColumn();
		int iMovedRow = posTemp->GetiRow();
		if(iMovedColumn == posEnd->GetiColumn() && iMovedRow == posEnd->GetiRow() )
		{
			// we have found the end position, roll back time
			struct Travail endTravail;
			endTravail.travailPos = posTemp;
			endTravail.prevPos = posStart;
			vTravails->push_back(endTravail);
			vDepthPosiitons.push_back(posTemp);
			visitedBoard[iMovedColumn-1][iMovedRow-1] = 1;//set to true
			return true;
		}
		//check if visited already
		for (int i = 0; i < iBoardSize; i++)
		{
			for (int i = 0; i < iBoardSize; i++)
			{
				if (this->visitedBoard[iMovedColumn-1][iMovedRow-1] == 1)
					return false;
			}
		}
		//now we have visited it, mark it as visited
		visitedBoard[iMovedColumn-1][iMovedRow-1] = 1;
		//and add it to this levels travail
		struct Travail thisTravail;
		thisTravail.travailPos = posTemp;
		thisTravail.prevPos = posStart;
		vTravails->push_back(thisTravail);
		vDepthPosiitons.push_back(posTemp);

	}
	return false;
};

string ChessBoard::GetKnightsTravail(Position* posStart, Position* posEnd)
{
	string strKnightsTravail = "";
	//using assumptions here that the end will be at ............. the end, although I could check for it. but I won't for now
	vector<string> vStrTravails;
	int iColumn = posEnd->GetiColumn();
	int iRow = posEnd->GetiRow();
	for(std::vector<Travail>::reverse_iterator it = vTravails.rbegin(); it != vTravails.rend(); ++it) 
	{
		struct Travail thisTravail;
		//thisTravail = vTravails.at(i);
		thisTravail = *it;
		Position* thisPos = thisTravail.travailPos;
		if (thisPos->GetiColumn() == iColumn && thisPos->GetiRow() == iRow )
		{
			vStrTravails.push_back(thisPos->GetPositionNotated());
			Position* prevPos = thisTravail.prevPos;
			iColumn = prevPos->GetiColumn();
            iRow = prevPos->GetiRow();
		}
	}
	// add it to the string in the correct direction
	for(std::vector<string>::reverse_iterator its = vStrTravails.rbegin(); its != vStrTravails.rend(); ++its) 
	{
		strKnightsTravail += *its + ' ';
	}
	strKnightsTravail += '\n';
	return strKnightsTravail;
};