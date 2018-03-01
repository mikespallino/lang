#pragma once

class InvalidToken {
public:
	InvalidToken(char val);
	friend std::ostream& operator<<(std::ostream& os, const InvalidToken& t);
private:
	char val;
};
