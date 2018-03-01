#pragma once

#include <iostream>
#include <string>

class Token
{
public:
	int type;
	std::string text;
	Token(int type, std::string text);
	friend std::ostream& operator<<(std::ostream& os, const Token& t);
};
