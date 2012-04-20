#ifndef _TESTBGRIMAGE_H_
#define _TESTBGRIMAGE_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

extern Hilaris& getHilaris();

class TestBGRImage : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestBGRImage);
	
		CPPUNIT_TEST(testCreate);
		CPPUNIT_TEST(testDebayerFast);
		CPPUNIT_TEST(testDebayerBilinear);
		CPPUNIT_TEST(testDebayerStandard);
		CPPUNIT_TEST(testDebayerHalfsize);
		
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void) {}
		void tearDown(void);

		void testCreate(void);
		void testDebayerFast();
		void testDebayerBilinear();
		void testDebayerStandard();
		void testDebayerHalfsize();
};

#endif
