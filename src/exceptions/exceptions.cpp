#include <iostream>
#include <string>
#include "exceptions.h"

InvalidToken::InvalidToken(char val)
{
    this->val = val;
}

std::ostream& operator<<(std::ostream& os, const InvalidToken& it)
{
    return os << "ERROR: InvalidToken <" << it.val << ">";
}

ParseError::ParseError(std::string msg)
{
    this->msg = msg;
}

std::ostream& operator<<(std::ostream& os, const ParseError& it)
{
    return os << "ERROR: " << it.msg;
}

LexError::LexError(std::string msg)
{
    this->msg = msg;
}

std::ostream& operator<<(std::ostream& os, const LexError& it)
{
    return os << "ERROR: " << it.msg;
}
