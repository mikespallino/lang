#include <string>
#include <iostream>

#include "list_lexer.h"

Token::Token(int type, std::string text)
{
    this->type = type;
    this->text = text;
}

std::ostream& operator<<(std::ostream& os, const Token& t)
{
    std::string name = ListLexer::tokenNames[t.type];
    return os << "<'" << t.text << "'," << name << ">";
}
