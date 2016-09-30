#include <string>
#include "ChessBoard.h"

using namespace std;

int main()
{
	//Position start, end; // set up a default Position ready for input
	string start, end;
	try
	{
		cin >> start >> end;//get the input
		Position posStart(start), posEnd(end);
		if (posStart.m_valid == 1 && posEnd.m_valid == 1)
		{
			ChessBoard chessboard; //initialise the board
			chessboard.RunBreadthFirstSearch(&posStart, &posEnd);
			string strKnightsTravail = "";
			strKnightsTravail = chessboard.GetKnightsTravail(&posStart, &posEnd);
			cout << strKnightsTravail ;
		}
	}
	catch (exception ex)
	{

		cout <<"error: " << ex.what() << endl;
	}
    cout << "Press ENTER to close...";
	cin.get();
	cin.get();
	return 0;
}