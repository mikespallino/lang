CC=g++
CFLAGS=-pedantic -Wall -c -W
LDFLAGS=-lcppunit
EXEC=lang
EXECTEST=test_lang
SRC=src/main.cpp src/lexer/token.cpp src/lexer/lexer.cpp src/lexer/list_lexer.cpp src/exceptions/exceptions.cpp src/parser/parser.cpp src/parser/list_parser.cpp
SRCTEST=test/test.cpp test/test_list_lexer.cpp src/lexer/token.cpp src/lexer/lexer.cpp src/lexer/list_lexer.cpp src/exceptions/exceptions.cpp src/parser/parser.cpp src/parser/list_parser.cpp
OBJ=$(SRC:.cpp=.o)
OBJTEST=$(SRCTEST:.cpp=.o)

all: $(SRC) $(EXEC)

$(EXEC): $(OBJ) 
	$(CC) $(LDFLAGS) $(OBJ) -o $@

$(EXECTEST): $(OBJTEST)
	$(CC) $(LDFLAGS) $(OBJTEST) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf src/*.o src/lexer/*.o src/exceptions/*.o src/parser/*.o test/*.o lang test_lang *.log *~ *.xml