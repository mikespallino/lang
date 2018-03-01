#include <cppunit/extensions/HelperMacros.h>
#include "../src/lexer/list_lexer.h"
#include "../src/lexer/token.h"
#include "test_list_lexer.h"
#include "../src/exceptions/exceptions.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ListLexerTest);

void ListLexerTest::TestBasicLex(void)
{
	ListLexer lexer = ListLexer("[a,b]");

	Token* t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::LBRACK);
	t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::NAME);
	t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::COMMA);
	t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::NAME);
	t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::RBRACK);
	t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::EOF_TYPE);
}

void ListLexerTest::TestIgnoreWhitespace(void)
{
	ListLexer lexer = ListLexer("[    a   \t,\n\n\n\r\r\nb    \n]\r\n");

	Token* t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::LBRACK);
	t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::NAME);
	t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::COMMA);
	t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::NAME);
	t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::RBRACK);
	t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::EOF_TYPE);
}


void ListLexerTest::TestInvalidToken(void)
{
	ListLexer lexer = ListLexer("[a,b+]");
	
	Token* t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::LBRACK);
	t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::NAME);
	t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::COMMA);
	t = lexer.nextToken();
	CPPUNIT_ASSERT(t->type == ListLexer::NAME);
	CPPUNIT_ASSERT_THROW(t = lexer.nextToken(), InvalidToken);

}
