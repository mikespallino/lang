#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class ListLexerTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(ListLexerTest);
	CPPUNIT_TEST(TestBasicLex);
	CPPUNIT_TEST(TestIgnoreWhitespace);
	CPPUNIT_TEST(TestInvalidToken);
	CPPUNIT_TEST_SUITE_END();

	public:
		void TestBasicLex(void);
		void TestIgnoreWhitespace(void);
		void TestInvalidToken(void);
};
