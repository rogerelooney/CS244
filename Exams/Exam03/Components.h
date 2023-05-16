#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <iostream>
#include <string>
#include <sstream>
#include <initializer_list>

class Action;
class Movement;
class Piece;
class Board;

class Point 
{
	private:
	int row;
	int column;

	public:
	Point() : Point(0,0) {}

	Point(int x,int y) : row(0), column(0)
	{
		if(row >= 0 && row <= 7 && column >= 0 && column <= 7)
		{
			row = x;
			column = y;
		}
	}

	Point(int idx) : Point(0,0)
	{
		NewIndex(idx);
	}

	Point(std::initializer_list<int> lt) : Point(0,0)
	{
		if(lt.size() == 2)
		{
			std::initializer_list<int>::iterator it = lt.begin();
			row = *it;
			++it;
			column = *it;
		}
	}

	Point(const Point& obj) 
	{
		row = obj.row;
		column = obj.column;
	}

	Point& operator=(const Point& rhs)
	{
		if(this != &rhs)
		{
			row = rhs.row;
			column = rhs.column;
		}
		return *this;
	}

	~Point() {}

	int Row() const 
	{ 
		return row; 
	}

	int Column() const 
	{
		return column;
	}

	int Index() const 
	{
		return ((8 * row) + column);
	}

	void NewRow(int value)
	{
		if(value >= 0 && value <= 7)
		{
			row = value;
		}
	}

	void NewColumn(int value) 
	{
		if(value >= 0 && value <= 7)
		{
			column = value;
		}
	}

	void NewIndex(int value) 
	{
		if(value >= 0 && value <= 63)
		{
			row = value / 8;
			column = value % 8;
		}
	}

	std::string ToString() const 
	{
		std::stringstream out;

		out << "(" << row << "," << column << ")";
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const Point& obj)
	{
		out << obj.ToString();
		return out;
	}
};

//Helper Functions
/*returns the change in the columns from Point s to e*/
int dX(const Point& s,const Point& e)
{
	return (e.Column() - s.Column());
}

/*returns the change in the rows from Point s to e*/
int dY(const Point& s,const Point& e)
{
	return (e.Row() - s.Row());
}

/*returns true only if the Points from a diagonal line*/	
bool MoveCheck(const Point& s,const Point& e)
{
	int x = abs(dX(s,e));
	int y = abs(dY(s,e));
	return (x != 0 && x == y); 
}

/*returns true only if the row increases from Point s to e*/
bool Increasing(const Point& s,const Point& e)
{
	return (e.Row() > s.Row());
}

#endif
