#ifndef TESTHILARIS_H
#define TESTHILARIS_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class TestHilaris : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestHilaris);
	CPPUNIT_TEST(testStartUp);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void) {}
		void tearDown(void) {}

		void testStartUp(void); 
};

#endif
