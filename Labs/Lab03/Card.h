#ifndef CARD_H
#define CARD_H

namespace LB3
{
    class Card
    {
        private:
        char suit;
        char symbol;
        string x;

        public:
        Card()
        {
            suit[x];
            symbol[x];
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

        const getter Suit() {}

        const getter Symbol() {}

        setter SetSuit()
        {
            
        }

        setter SetSymbol()
        {

        }

        const string ToString()
        {
            string x = symbol;
            string y = suit;
            return [x:y];
        }
    };
}

#endif