#include <iostream>
#include "lexer/token.h"
#include "lexer/lexer.h"
#include "lexer/list_lexer.h"

int main(int argc, char** argv)
{
	if (argc < 2 || argc > 3)
	{
		std::cout << "USAGE ./lang EXPRESSION" << std::endl;
		return -1;
	}
	
	ListLexer lexer = ListLexer(argv[1]);
	Token* t = lexer.nextToken();
	while (t->type != Lexer::EOF_TYPE)
	{
		std::cout << *t << std::endl;
		t = lexer.nextToken();
	}

	std::cout << *t << std::endl;
	
	return 0;
}