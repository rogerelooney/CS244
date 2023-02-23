// Anything within comments, was done during a lecture on 02/23.
#ifndef INTERVAL_H
#define INTERVAL_H
/*
#include <iostream>
#include <string>
*/

namespace PS5
{
    class Interval
    {
        public:
        double endpoints[2];
        bool included[2];
        /*
        Interval() : endpoints{0,10}
        {
            included[0] = true;
            included[1] = true;
        }

        Interval(const Interval& obj)
        {
            for(int i = 0; i < 2; i += 1)
            {
                endpoints[i] = obj.endpoints[i];
                included[i] = obj.included[i];
            }
        }

        Interval& operator=(const Interval& obj)
        {
            if(this != &obj)
            {
                for(int i = 0; i < 2; i += 1)
                {
                    endpoints[i] = obj.endpoints[i];
                    included[i] = obj.included[i];
                }
            }
            return *this;
        }

        ~Interval() {}
        */
    };
}

#endif