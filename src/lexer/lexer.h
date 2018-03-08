#pragma once

#include <string>
#include "token.h"

class Lexer
{
public:
    static const int EOF_TYPE = 1;
    static const char EOF_CHAR;
    std::string input;
    int p;
    char c;
    Lexer(std::string input);
    void consume();
    void match(char x);
    virtual Token* nextToken() = 0;
    virtual std::string getTokenName(int tokenType) = 0;
};
