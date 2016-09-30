
#include <iostream>
#include <string.h>
#include <stdexcept>
#include "Position.h"


Position::Position(char Row, char Column)
{
	Position::m_valid = true;
}

Position::Position(string strPos)
{
		m_valid = false;
		int iLength = strPos.length();
		if(iLength != 2)
			cout <<"\n error: in Position creation from Char, please use the correct Chess notation eg A1 H8 \n";
        
        Column col = toupper(strPos[0]);
        Row row = strPos[1];
        
        if( IsColumnValid(col) && IsRowValid(row) )
        {
            m_column = col;
			m_iColumn = ConvertColumnToInt(m_column);
            m_row = row;
			m_iRow = (int)m_row - 48;
			Position::m_valid = true;
        }
        else
        {
			cout <<"\n error: the column and/or the row are out of the range A1 - H8 \n";
        }
};

Position::Position(const Position &obj)
{
	Position::m_valid = true;
	Column cColumn;// = new Column;
	Row rRow;// = new Row;
	int iColumn;// = new int;
	int iRow;// = new int;

	cColumn = obj.m_column;
	rRow = obj.m_row;
	iColumn = obj.m_iColumn;
	iRow = obj.m_iRow;
	

};

Position::~Position(void)
{
	//delete this;
};

Position* Position::MovePosition(int iColumn, int iRow)
{
	m_iColumn += iColumn;
	m_column = ConvertIntToColumn(m_iColumn);
	m_iRow += iRow;
	m_row = m_iRow + 48;
	return this;
}

bool Position::IsColumnValid(char column)
{
	int iColumn = ConvertColumnToInt(column);
	if (iColumn < 9)
		return true;
	return false;
};

bool Position::IsRowValid(char row)
{
	int iRow = (int)row - 48;
	if (iRow < 9)
		return true;
	return false;

};

bool Position::IsMoveValid(int iColumnMove, int iRowMove)
{
	try
	{
		int iColumn = m_iColumn + iColumnMove;
		if (iColumn > 8 || iColumn < 1)
			return false;

		int iRow = m_iRow + iRowMove;
		if (iRow > 8 || iRow < 1)
			return false;

		return true;

	}
	catch (exception ex)
	{
		cout <<"\n error: " << ex.what() << endl;
		return false;
	}

	return false;
}

int Position::ConvertColumnToInt(char column)
{
	switch(tolower(column)){
		case 'a':
			return 1;
		case 'b':
			return 2;
		case 'c':
			return 3;
		case 'd':
			return 4;
		case 'e':
			return 5;
		case 'f':
			return 6;
		case 'g':
			return 7;
		case 'h':
			return 8;
	}
	return -1;
}

char Position::ConvertIntToColumn(int iColumn)
{
	switch(iColumn){
		case 1:
			return 'A';
		case 2:
			return 'B';
		case 3:
			return 'C';
		case 4:
			return 'D';
		case 5:
			return 'E';
		case 6:
			return 'F';
		case 7:
			return 'G';
		case 8:
			return 'H';
	}	
	return 'Z';
}
string Position::GetPositionNotated()
{
	string strNotated = "";

	strNotated += m_column;
	strNotated += m_row;

	return strNotated;
}
