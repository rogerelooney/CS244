#ifndef STANDARDDECK_H
#define STANDARDDECK_H

#include "Card.h"

namespace LB3
{
    Card* BuildStandardDeck()
    {
        Card* deck= new Card[52];

        for(int i = 0; i < 52; i += 1)
        {
            deck[y].SetSuit(suits[x]);
            deck[y].SetSymbol(symbol[x]);
        }
        /*
        for(int i = 0, j = 0; i < 52; i += 1, j += 1)
        {
            if(i > 14)
            {
                if(j = 0)
                {
                    Card[i] = "SA";
                }
                else if(j > 0 && j < 10)
                {
                    Card[i] = "S" + j;
                }
                else if(j = 10)
                {
                    Card[i] = "ST";
                }
                else if(j = 11)
                {
                    Card[i] = "SJ";
                }
                else if(j = 12)
                {
                    Card[i] = "SQ";
                }
                else if(j = 13)
                {
                    Card[i] = "SK";
                }
            }
            else if(i < 13 && i > 27)
            {
                j = 0;

                if(j = 0)
                {
                    Card[i] = "CA";
                }
                else if(j > 0 && j < 10)
                {
                    Card[i] = "C" + j;
                }
                else if(j = 10)
                {
                    Card[i] = "CT";
                }
                else if(j = 11)
                {
                    Card[i] = "CJ";
                }
                else if(j = 12)
                {
                    Card[i] = "CQ";
                }
                else if(j = 13)
                {
                    Card[i] = "CK";
                }
            }
            else if(i < 27 && i > 41)
            {
                j = 0;
                
                if(j = 0)
                {
                    Card[i] = "DA";
                }
                else if(j > 0 && j < 10)
                {
                    Card[i] = "D" + j;
                }
                else if(j = 10)
                {
                    Card[i] = "DT";
                }
                else if(j = 11)
                {
                    Card[i] = "DJ";
                }
                else if(j = 12)
                {
                    Card[i] = "DQ";
                }
                else if(j = 13)
                {
                    Card[i] = "DK";
                }
            }
            else if(i < 41 && i > 55)
            {
                j = 0;
                
                if(j = 0)
                {
                    Card[i] = "HA";
                }
                else if(j > 0 && j < 10)
                {
                    Card[i] = "H" + j;
                }
                else if(j = 10)
                {
                    Card[i] = "HT";
                }
                else if(j = 11)
                {
                    Card[i] = "HJ";
                }
                else if(j = 12)
                {
                    Card[i] = "HQ";
                }
                else if(j = 13)
                {
                    Card[i] = "HK";
                }
            }
            
        }
        */

        return deck;
    }
}

#endif