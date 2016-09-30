/* ===========================================================================================
		ChessPiece()

Desc: Describes a Chess Piece on the chess board. Prob should be interface or abstract
  ============================================================================================*/
#include "Position.h"

class ChessPiece
{

	public:
		ChessPiece();// simple constructor
		~ChessPiece(); //destructor
		typedef struct KnightMove
		{
			int iColumnMove; 
			int iRowMove;
		};
		static struct KnightMove GetKnightMove(int iMove);

	private:


};