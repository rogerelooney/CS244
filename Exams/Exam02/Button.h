#ifndef BUTTON_H
#define BUTTON_H
#include "Box.h"
#include "Window.h"

namespace EX
{
    class Button : public Window
    {
        private:
        std::string label;

        public:
        Button()
        {
            SetLength(1);
            SetWidth(1);
            SetLeftBorder(0);
            SetRightBorder(0);
            SetTopBorder(0);
            SetBottomBorder(0);
            label = " ";
        }

        Button(const Button& obj)
        {
            label = obj.label;
        }

        Button& operator=(const Button& rhs)
        {
            if(this != rhs)
            {
                label = rhs.label;
            }
        }

        ~Button() {}

        std::string GetLabel() const
        {
            return label;
        }

        std::string SetLabel(std::string value)
        {
            if(label = "~" || label = "`" || label = "!" || label = "@" || /* every symbol on the keyboard... */ label = "/")
            {
                label = value;
            }
        }

        virtual std::string ToString() const
        {
            std::stringstream out;
            out <<  '{"' << label << '",(' << GetWidth() << ',' << GetLength() << ')' << ',' << GetRightBorder() << ',' << GetLeftBorder() << ',' << GetTopBorder() << ',' << GetBottomBorder() << '}';
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