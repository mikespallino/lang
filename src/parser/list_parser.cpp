#include "list_parser.h"
#include "../lexer/list_lexer.h"
#include "../exceptions/exceptions.h"

void ListParser::list()
{
    match(ListLexer::LBRACK);
    elements();
    match(ListLexer::RBRACK);
}

void ListParser::elements()
{
    element();
    while(lookahead->type==ListLexer::COMMA)
    {
        match(ListLexer::COMMA);
        element();
    }
}

void ListParser::element()
{
    if(lookahead->type == ListLexer::NAME)
    {
        match(ListLexer::NAME);
    }
    else if (lookahead->type == ListLexer::LBRACK)
    {
        list();
    }
    else
    {
        throw ParseError("Expecting name or list; found <'" + lookahead->text + "'," + ListLexer::tokenNames[lookahead->type] + ">");
    }
}
