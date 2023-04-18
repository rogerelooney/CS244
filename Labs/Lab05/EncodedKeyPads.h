#ifndef ENCODEDKEYPAD_H
#define ENCODEDKEYPAD_H
#include "KeyPad.h"
#include "Encoders.h"
#include <string>

using namespace std;

namespace LB5
{
    class CXKeyPad : public KeyPad
    {
        public:
        std::string CreateEncoder() : CreateEncoder()
        {
            
        }

        friend std::ostream& operator<<(std::ostream& out,const EncodedKeyPad& obj)
		{
			out << obj.ToString();
			return out;
		}
    };

    class NTKeyPad : public KeyPad
    {
        public:
        std::string CreateEncoder() : CreateEncoder()
        {
            
        }

        friend std::ostream& operator<<(std::ostream& out,const EncodedKeyPad& obj)
		{
			out << obj.ToString();
			return out;
		}
    };
}

#endif