/* ===========================================================================================
		ChessBoard()

Desc: Describes a Chess  board. 
  ============================================================================================*/
#include "vector"
#include <string>
#include "ChessPiece.h"
using namespace std;

class ChessBoard
{

private:
	struct Travail
	{
		Position* travailPos;
		Position* prevPos;
	};

	vector<Travail> vTravails;
	bool visitedBoard[8][8];
	bool flag;
	static const int iBoardSize = 8;
	bool SearchByMove(ChessPiece KnightPiece, int iMove, vector<Travail>* vTravails, Position* posStart, Position* posEnd, vector<Position*> &vDepthPosiitons );

public:
	ChessBoard(); //empty constructor
	//~ChessBoard(); //destructor
	void RunBreadthFirstSearch(Position* posStart, Position* posEnd);
	string GetKnightsTravail(Position* posStart, Position* posEnd);

};