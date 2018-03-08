#include "lexer.h"
#include "../exceptions/exceptions.h"
#include <string>

#include <iostream>

const char Lexer::EOF_CHAR = -1;

Lexer::Lexer(std::string input)
{
    p = 0;
    this->input = input;
    c = input.at(p);
}

void Lexer::consume() {
    p++;
    if (p >= input.length())
    {
        c = EOF_CHAR;
    }
    else
    {
        c = input.at(p);
    }
}

void Lexer::match(char x) {
    if (c == x)
    {
        consume();
    }
    else
    {
        char buff[21];
        sprintf(buff, "Expecting %c; found %c", x, c);
        throw LexError(buff);
    }
}
