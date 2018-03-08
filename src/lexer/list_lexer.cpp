#include "list_lexer.h"
#include "token.h"
#include "../exceptions/exceptions.h"

const std::string ListLexer::tokenNames[] = {"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK"};

Token* ListLexer::nextToken()
{
    while (c != EOF)
    {
        switch(c)
        {
            case ' ': case '\t': case '\n': case '\r': WS(); continue;
            case ',': consume(); return new Token(COMMA, ",");
            case '[': consume(); return new Token(LBRACK, "[");
            case ']': consume(); return new Token(RBRACK, "]");
            default:
                if (isLETTER())
                {
                    return name();
                }
                else
                {
                    throw InvalidToken(c);
                }
        }
    }

    return new Token(EOF_TYPE, "<EOF>");
}

Token* ListLexer::name()
{
    //TODO use non static buffer
    char buff[1024];
    int i = 0;
    do
    {
        buff[i] = c;
        consume();
        i++;
    } while (isLETTER());
    return new Token(NAME, buff);
}

void ListLexer::WS() {
    while(c==' ' || c=='\t' || c=='\n' || c=='\r')
    {
        consume();
    }
}

bool ListLexer::isLETTER() {
    return (c >='a' && c <='z') || (c >='A' && c <= 'Z');
}

std::string ListLexer::getTokenName(int tokenType)
{
    return tokenNames[tokenType];
}
