#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Components.h"
#include "Action.h"

class Piece
{
	private:
	Point point;
	Action* type;
	bool team;
	bool active;

	public:
	Piece() : Piece({0,0},false,NULL) {}

	Piece(const Point& p,bool team) : Piece(p,team,NULL) {}

	Piece(const Point& p,bool team,Action* type) : point(p), team(team), active(true) 
	{
		this->type = type;

		if(type != NULL)
		{
			type->SetPiece(this);
		}	
	}

	~Piece() {}

	Piece(const Piece& obj)
	{
		point = obj.point;
		team = obj.team;
		active = obj.active;
	}

	Piece& operator=(const Piece& rhs)
	{
		if(this != &rhs)
		{
			point = rhs.point;
			team = rhs.team;
			active = rhs.active;
		}
		return *this;
	}

	Point& GetPoint() 
	{
		return point;
	}

	const Point& GetPoint() const 
	{
		return point;
	}

	bool GetTeam() const 
	{
		return team;
	}

	bool IsActive() const 
	{
		return active;
	}

	void ChangeStatus() 
	{
		active = !active;
	}

	void ChangeType(Action* value)
	{
		if(value != NULL)
		{
			type = value;
			type->SetPiece(this);
		}
	}

	std::string ToString() const
	{
		return ((type != NULL)?(type->ToString()):(" "));
	}

	char Move(const Point& p)
	{
		return ((type != NULL)?(type->Move(p)):('\0'));
	}

	friend std::ostream& operator<<(std::ostream& out,const Piece& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif
