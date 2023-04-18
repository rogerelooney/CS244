#ifndef ENCODERS_H
#define ENCODERS_H
#include "KeyPad.h"
#include <string>

using namespace std;

namespace LB5
{
    class ShiftEncoder : public Encoder
    {
        public:
        std::string Encipher(char value) : Encipher() {}
        {
            return char('0' + ((value - '0') + 4) % 10);
        }
    };

    class AffineEncoder : public Encoder
    {
        public:
        std::string Encipher(char value) : Encipher() {}
        {
            return char('0' + (7 * (value - '0') + 2) % 10);
        }
    };
}

#endif