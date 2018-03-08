#include <iostream>
#include "lexer/token.h"
#include "lexer/list_lexer.h"
#include "parser/list_parser.h"
#include "exceptions/exceptions.h"

int main(int argc, char** argv)
{
    if (argc < 2 || argc > 3)
    {
        std::cout << "USAGE ./lang EXPRESSION" << std::endl;
        return -1;
    }
    
    try
    {
        ListLexer* lexer = new ListLexer(argv[1]);
        ListParser parser = ListParser(lexer);
        parser.list();
    }
    catch (InvalidToken er)
    {
        std::cout << std::endl << er << std::endl;
    }
    catch (ParseError er)
    {
        std::cout << std::endl << er << std::endl;
    }
    return 0;
}
