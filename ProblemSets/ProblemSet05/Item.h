// Anything within comments, was done during a lecture on 02/16, with additional notes from 02/23.
#ifndef ITEM_H
#define ITEM_H

#include <string>
// #include "Point.h"
//using namespace std;

namespace PS5
{
    class Item
    {
        public:
        string id;
        /*
        Point* position;

        Item()
        {
            id = "";
            position = new Point();
        }

        Item(const Item& obj)
        {
            id = obj.id;
            position = new Point();
            *position = *(obj.position);
        }

        Item& operator=(const Item& rhs)
        {
            if(this != &rhs)
            {
                id = rhs.id;
                delete position;
                position = new Point();
                *position = *(rhs.position);
            }
            return *this;
        }

        ~Item()
        {
            delete position;
        }
        */
    };
}

#endif