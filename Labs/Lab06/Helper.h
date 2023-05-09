#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string>

#define UPPERS std::string("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
#define LOWERS std::string("abcdefghijklmnopqrstuvwxyz")
#define DIGITS std::string("0123456789")

bool Contains(std::string str,char ch)
{
	return str.find(ch) != std::string::npos;
}

#endif
