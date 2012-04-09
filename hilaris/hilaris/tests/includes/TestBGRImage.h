#ifndef _TESTBGRIMAGE__H_
#define _TESTBGRIMAGE_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class TestBGRImage : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestBGRImage);
	
		CPPUNIT_TEST(testCreate);
		
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void) {}
		void tearDown(void) {}

		void testCreate(void);
};

#endif
