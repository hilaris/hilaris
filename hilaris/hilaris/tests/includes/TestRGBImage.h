#ifndef _TESTRGBIMAGE_H_
#define _TESTRGBIMAGE_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

extern Hilaris& getHilaris();

class TestRGBImage : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestRGBImage);
	
		CPPUNIT_TEST(testCreate);
		CPPUNIT_TEST(testDebayerFast);
		
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void) {}

		void testCreate(void);
		void testDebayerFast(void);
};

#endif
