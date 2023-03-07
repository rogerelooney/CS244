#ifndef UNODECK_H
#define UNODECK_H

#include "Card.h"

namespace LB3
{
    Card* BuildUnoDeck()
    {
        Card* deck= new Card[108];

        return deck;
    }
}

#endif