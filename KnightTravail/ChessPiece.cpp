#include "ChessPiece.h"


ChessPiece::ChessPiece()
{
};
ChessPiece::~ChessPiece()
{
};
struct ChessPiece::KnightMove ChessPiece::GetKnightMove(int iMove)
{
	KnightMove movingnight;
	switch(iMove){
		case 1:
			movingnight.iColumnMove = 1;
			movingnight.iRowMove = 2;
			break;
		case 2:
			movingnight.iColumnMove = 1;
			movingnight.iRowMove = -2;
			break;
		case 3:
			movingnight.iColumnMove = -1;
			movingnight.iRowMove = 2;
			break;
		case 4:
			movingnight.iColumnMove = -1;
			movingnight.iRowMove = -2;
			break;
		case 5:
			movingnight.iColumnMove = 2;
			movingnight.iRowMove = 1;
			break;
		case 6:
			movingnight.iColumnMove = 2;
			movingnight.iRowMove = -1;
			break;
		case 7:
			movingnight.iColumnMove = -2;
			movingnight.iRowMove = 1;
			break;
		case 8:
			movingnight.iColumnMove = -2;
			movingnight.iRowMove = -1;
			break;
	}

	return movingnight;
};



