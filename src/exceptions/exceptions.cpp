#include <iostream>
#include "exceptions.h"

InvalidToken::InvalidToken(char val)
{
	this->val = val;
}

std::ostream& operator<<(std::ostream& os, const InvalidToken& it)
{
	return os << "ERROR: InvalidToken <" << it.val << ">";
}
