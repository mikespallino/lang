#pragma once

#include "lexer.h"
#include <string>

class ListLexer:public Lexer {
public:
	Token* name();
	void WS();
	bool isLETTER();
	ListLexer(std::string input):Lexer(input) {};
	Token* nextToken();
	std::string getTokenName(int tokenType);

	static const int NAME = 2;
	static const int COMMA = 3;
	static const int LBRACK = 4;
	static const int RBRACK = 5;
	static const std::string tokenNames[6];
};