#ifndef WINDOW_H
#define WINDOW_H
#include "Box.h"

namespace EX
{
    class Window : public Box
    {
        private:
        int border[4];

        public:
        Window()
        {
            SetLength(1);
            SetWidth(1);
            for(int i = 0; i < 4; i += 1)
            {
                border[i] = 0;
            }
        }

        Window(const Window& obj)
        {
            for(int i = 0; i < 4; i += 1)
            {
                border[i] = obj.border[i];
            }
        }

        Window& operator=(const Window& rhs)
        {
            if(this != rhs)
            {
                for(int i = 0; i < 4; i += 1)
                {
                    border[i] = rhs.border[i];
                }
            }
        }

        ~Window() {}

        int GetLeftBorder() const
        {
            return border[0];
        }

        int GetRightBorder() const
        {
            return border[1];
        }

        int GetTopBorder() const
        {
            return border[2];
        }

        int GetBottomBorder() const
        {
            return border[3];
        }

        int SetLeftBorder(int value)
        {
            if(value >= 0)
            {
                border[0] = value;
            }
        }

        int SetRightBorder(int value)
        {
            if(value >= 0)
            {
                border[1] = value;
            }
        }

        int SetTopBorder(int value)
        {
            if(value >= 0)
            {
                border[2] = value;
            }
        }

        int SetBottomBorder(int value)
        {
            if(value >= 0)
            {
                border[3] = value;
            }
        }

        virtual std::string ToString() const
        {
            std::stringstream out;
            out << "[(" << GetLength() << "," << GetWidth() << ")," << border[0] << "," << border[1] << "," << border[2] << "," << border[3] << "]";
            return out.str();
        }

        std::string ostream& operator<<(ostream out, const ToString& obj)
        {
            out << obj.Tostring();
            return out;
        }
    };
}

#endif