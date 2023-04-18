#ifndef EXTRA_H
#define EXTRA_H
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

class Character
{
    private:
    std::string name;
    int type;
    int offense;
    int defense;

    public:
    Character()
    {
        name = "name";
        type = 0;
        offense = 100;
        defense = 100;
    }

    Character(const Character& obj)
    {
        name = obj.name;
        type = obj.type;
        offense = obj.offense;
        defense = obj.defense;
    }

    Character operator=(const Character& rhs)
    {
        if(this != &rhs)
        {
            name = rhs.name;
            type = rhs.type;
            offense = rhs.offense;
            defense = rhs.defense;
        }
        return *this;
    }

    ~Character() {}

    std::string GetName() const
    {
        return name;
    }

    int GetType() const
    {
        return type;
    }

    int GetOffense() const
    {
        return offense;
    }

    int GetDefense() const
    {
        return defense;
    }

    std::string SetName(std::string value)
    {
        if(value != 0 || value != 1 || value != 2 || value != 3 || value != 4 || value != 5 || value != 6 || value != 7 || value != 8 || value != 9)
        {
            name = value;
        }
    }

    int SetType(int value)
    {
        if(value >= 1 && value <= 50)
        {
            type = value;
        }
    }

    int SetOffense(int value)
    {
        if(value >= 1 && value <= 5000)
        {
            offense = value;
        }
    }
    
    int SetDefense(int value)
    {
        if(value >= 1 && value <= 5000)
        {
            defense = value;
        }
    }

    virtual std::string ToString() const
    {
        std::stringstream out;
        out << '[' << name << '(' << type << '):' << offense << '/' << defense << ']';
        return out.str();
    }

    virtual Character* Clone() const = 0;

    friend std::ostream& operator<<(std::ostream& out,const Character& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif