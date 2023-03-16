#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <sstream>

namespace EP
{
	class Board
	{
		public:
		std::string board[6];
		static const char tokens[2];

		Board()
		{
			for(int i = 0;i < 6;i += 1)
			{
				board[i] = "*******";
			}
		}

		Board(std::string value)
		{
			for(int i = 0;i < 6;i += 1)
			{
				board[i] = value;
			}
		}

		Board(const Board& obj)
		{
			for(int i = 0;i < 6;i += 1)
			{
				board[i] = obj.board[i];
			}
		}

		Board& operator=(const Board& rhs)
		{
			if(this != &rhs)
			{
				for(int i = 0;i < 6;i += 1)
				{
					board[i] = rhs.board[i];
				}
			}
			return *this;
		}

		~Board() {}

		std::string ToString() const
		{
			std::stringstream out;

			for(int i = 0;i < 6;i += 1)
			{
				for(int j = 0;j < board[i].length();j += 1)
				{
					out << board[i][j];

					if(j + 1 < board[i].length())
					{
						out << " ";
					}
					else
					{
						out << "\n";
					}
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

	const char Board::tokens[2] = {'O','X'};
}
#endif
