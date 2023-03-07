#ifndef UNODECK_H
#define UNODECK_H

#include "Card.h"

namespace LB3
{
    Card* BuildUnoDeck()
    {
        Card* deck= new Card[108];
        for(int i = 0; i < 108; i += 1)
        {
            deck[y].SetSuit(suits[x]);
            deck[y].SetSymbol(symbol[x]);
        }

        return deck;
    }
}

#endif