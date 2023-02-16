#ifndef POINT_H
#define POINT_H

namespace PS5
{
    class Point
    {
        public:
        int x;
        int y;

        /* Done after lecture on 02/16.
        
        Point()
        {
            x = 0;
            y = 0;
        }

        Point(const Point& obj)
        {
            x = obj.x;
            y = obj.y;
        }

        Point& operator=(const Point& obj)
        {
            if(this != &obj)
            {
                x = obj.x;
                y = obj.y;
            }
            return *this;
        }

        ~Point() {}

        */
    };
}

#endif