#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <sstream>
#include "Components.h"

class Action 
{
	protected:
	Piece* piece;

	public:
	Action() : piece(NULL) {}

	void SetPiece(Piece* value)
	{
		piece = value;
	}

	virtual std::string ToString() const = 0;
	virtual char Move(const Point& p) = 0;
};

#endif
