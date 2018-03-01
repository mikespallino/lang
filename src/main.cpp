#include <iostream>
#include "lexer/token.h"
#include "lexer/lexer.h"
#include "lexer/list_lexer.h"
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
		ListLexer lexer = ListLexer(argv[1]);
		Token* t = lexer.nextToken();
		while (t->type != Lexer::EOF_TYPE)
		{
			std::cout << *t << std::endl;
			t = lexer.nextToken();
		}

		std::cout << *t << std::endl;
	}
	catch (InvalidToken er)
	{
		std::cout << std::endl << er << std::endl;
	}
	return 0;
}
