#include "parser.h"
#include "../lexer/list_lexer.h"
#include "../exceptions/exceptions.h"

Parser::Parser(Lexer* lexer)
{
    this->input = lexer;
    lookahead = input->nextToken();
}

void Parser::match(int x)
{
    if(lookahead->type == x)
    {
        consume();
    }
    else
    {
        throw ParseError("expecting " + input->getTokenName(x) + "; found <'" + lookahead->text + "'," + ListLexer::tokenNames[lookahead->type] + ">");
    }
}

void Parser::consume()
{
    lookahead = input->nextToken();
}
