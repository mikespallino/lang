#pragma once

#include "../lexer/token.h"
#include "../lexer/lexer.h"

class Parser {
public:
    void match(int x);
    void consume();
    Parser(Lexer* lexer);
    Lexer* input;
    Token* lookahead;
};
