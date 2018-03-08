#pragma once
#include <string>

class InvalidToken {
public:
    InvalidToken(char val);
    friend std::ostream& operator<<(std::ostream& os, const InvalidToken& t);
private:
    char val;
};

class ParseError {
public:
    ParseError(std::string msg);
    friend std::ostream& operator<<(std::ostream& os, const ParseError& t);
private:
    std::string msg;
};

class LexError {
	public:
    LexError(std::string msg);
    friend std::ostream& operator<<(std::ostream& os, const LexError& t);
private:
    std::string msg;
};
