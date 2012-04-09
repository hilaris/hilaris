#ifndef _TESTGREYSCALEIMAGE_H_
#define _TESTGREYSCALEIMAGE_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class TestGreyscaleImage : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestGreyscaleImage);
	
		CPPUNIT_TEST(testCreate);
		
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void) {}
		void tearDown(void) {}

		void testCreate(void);
};

#endif
