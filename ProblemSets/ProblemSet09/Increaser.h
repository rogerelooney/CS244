#ifndef INCREASER_H
#define INCREASER_H

namespace PS9
{
    class Increaser
    {
        public:
        virtual void Increment() = 0;
        virtual bool CanIncrement() const = 0;
    };
}

#endif