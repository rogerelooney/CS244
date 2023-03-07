#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

namespace LB3
{
    class Card
    {
        private:
        char suit;
        char symbol;
        string x, y, z;

        public:
        Card()
        {
            suit = x;
            symbol = x;
        }

        Card(const Card& obj)
        {
            suit = obj.suit;
            symbol = obj.symbol;
        }

        Card& operator=(const Card& rhs)
        {
            suit = rhs.suit;
            symbol = rhs.symbol;
        }

        ~Card() {}

        const char getSuit()
        {
            return suit;
        }

        const char getSymbol()
        {
            return symbol;
        }

        char SetSuit()
        {
            suit = Y;
        }

        char SetSymbol()
        {
            symbol = X;
        }

        const string ToString()
        {
            x = symbol;
            y = suit;
            z = "[" x + ":" + y "]";
            return z;
        }

        friend ostream& operator<<(ostream& out, const Card& obj)
        {
            out << obj.ToString();
            return out;
        }
    };
}

#endif