#ifndef _TESTGREYSCALEIMAGE_H_
#define _TESTGREYSCALEIMAGE_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

extern Hilaris& getHilaris();

class TestGreyscaleImage : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestGreyscaleImage);
	
		CPPUNIT_TEST(testCreate);
		CPPUNIT_TEST(testDebayerFast);
		CPPUNIT_TEST(testDebayerHalfsize);
		CPPUNIT_TEST(testDebayerVector);
		
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void) {}
		void tearDown(void) {}

		void testCreate(void);
		void testDebayerFast(void);
		void testDebayerHalfsize(void);
		void testDebayerVector(void);
};

#endif
