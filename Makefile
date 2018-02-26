CC=g++
CFLAGS=-pedantic -Wall -c -W
LDFLAGS=-lcppunit
EXEC=lang
EXECTEST=test_lang
SRC=src/main.cpp src/lexer/token.cpp src/lexer/lexer.cpp src/lexer/list_lexer.cpp
SRCTEST=test/test.cpp test/test_list_lexer.cpp src/lexer/token.cpp src/lexer/lexer.cpp src/lexer/list_lexer.cpp
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
	rm -rf src/*.o src/lexer/*.o test/*.o lang test_lang *.log *~ *.xml