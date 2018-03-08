#pragma once
#include "parser.h"
#include "../lexer/list_lexer.h"

class ListParser: public Parser
{
public:
    ListParser(ListLexer* lexer):Parser(lexer) {};
    void list();
    void elements();
    void element();
};
