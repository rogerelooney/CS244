#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include "Components.h"
#include "Piece.h"

class Board 
{
	private:
	Piece* grid[64];
	bool capture;
	Board(const Board&);
	Board& operator=(const Board&);

	Piece* PathCheck(Piece* c,const Point& p)
	{
		Piece* t = NULL;
		Point a = c->GetPoint();
		int start = a.Index();
		int end = p.Index();
		int step = ((dY(a,p) < 0)?(-8):(8)) + ((dX(a,p) < 0)?(-1):(1));

		for(int i = start + step;i < end;i += step)
		{
			if(grid[i] != NULL)
			{
				if(t != NULL || grid[i]->GetTeam() == c->GetTeam())
				{
					return NULL;
				}
				else 
				{
					t = grid[i];
				}
			}
		}
		return (t == NULL)?(c):(t);
	}
			
	public:
	Board() 
	{
		for(int i = 0;i < 64;i += 1)
		{
			grid[i] = NULL;
		}
		capture = false;
	}

	~Board() {}

	void AddPiece(Piece* p)
	{
		if(p != NULL && p->GetPoint().Row() % 2 != p->GetPoint().Column() % 2)
		{
			grid[p->GetPoint().Index()] = p;
		}
	}

	bool HasCaptured() const 
	{
		return capture;
	}

	bool IsPlayable(const Point& p,bool team)
	{
		return (grid[p.Index()] != NULL && grid[p.Index()]->GetTeam() == team);
	}

	char Move(const Point& s,const Point& e)
	{
		if(grid[s.Index()] != NULL && grid[e.Index()] == NULL) 
		{
			Piece* p = grid[s.Index()];
			char n = p->Move(e);

			if(n != '\0') 
			{
				Piece* t = PathCheck(p,e);

				if((n == 'm' || n == 'b') && p == t)
				{
					p->GetPoint() = e;
					grid[e.Index()] = p;
					grid[s.Index()] = NULL;
					return 'm';
				}
				else if((n == 'c' || n == 'b') && t != NULL)
				{
					p->GetPoint() = e;
					grid[e.Index()] = p;
					grid[s.Index()] = NULL;
					t->ChangeStatus();
					grid[t->GetPoint().Index()] = NULL;
					return 'c';
				}
			}
		}
		return '\0';
	}

	void Reset() 
	{
		for(int i = 0;i < 64;i += 1)
		{
			grid[i] = NULL;
		}
		capture = false;
	}

	std::string ToString() const 
	{
		std::stringstream out;
		out << "   0  1  2  3  4  5  6  7\n";

		for(int i = 0;i < 64;i += 1)
		{
			if(i % 8 == 0)
			{
				out << (i / 8) << " ";
			}
			out << "[";
	
			if(grid[i] == NULL)
			{
				out << (((i % 8) % 2 == (i / 8) % 2)?("="):(" "));
			}
			else 
			{
				out << *(grid[i]);
			}	
			out << "]";
		
			if((i + 1) % 8 == 0)
			{
				out << "\n";
			}
		}
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const Board& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif 
