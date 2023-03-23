#ifndef DECREASER_H
#define DECREASER_H

namespace PS9
{
    class Decreaser
    {
        public:
        virtual void Decrement() = 0;
        virtual bool CanDecrement() const = 0;
    };
}

#endif