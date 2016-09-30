/* ===========================================================================================
		Position()

Desc: Describes a position in the chess board in various formats
  ============================================================================================*/
#include <iostream>
#include <string>

using namespace std;

class Position
{
	public:
		typedef char Column, Row;
		static const Column minCol = 'A';
		static const Column maxCol = 'H';
		static const Row minRow = '1';
		static const Row maxRow = '8';

		Position(char Column, char Row);
		Position(string strPos);
		
		Position() : m_column(minCol), m_row(minRow) {}; //default constructor
		Position(const Position &obj); //copy constructor
		~Position(); //destructor


		bool IsColumnValid(char column);
		bool IsRowValid(char row);
		bool IsMoveValid (int iColumnMove, int iRowMove);

		void SetColumn(int iColumn) { m_column = iColumn; };
		char GetColumn(){return m_column;};
		int GetiColumn(){return m_iColumn;};
		string GetPositionNotated();
		
		void SetRow(int iRow) { m_row = iRow; };
		char GetRow(){return m_row;};
		int GetiRow(){return m_iRow;};
		bool m_valid;

		Position* MovePosition(int Column, int Row);


	private:
		Column m_column;
		Row m_row;
		int m_iColumn;
		int m_iRow;

		int ConvertColumnToInt(char column);
		char ConvertIntToColumn(int iColumn);

};