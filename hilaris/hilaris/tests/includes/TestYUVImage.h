#ifndef _TESTYUVIMAGE_H_
#define _TESTYUVIMAGE_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Hilaris.h"

extern Hilaris& getHilaris();

class TestYUVImage : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestYUVImage);
	
		CPPUNIT_TEST(testDebayerFast);
		CPPUNIT_TEST(testDebayerFastY);
		CPPUNIT_TEST(testDebayerFastU);
		CPPUNIT_TEST(testDebayerFastV);
		
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void) {}
		void tearDown(void);

		void testDebayerFast(void);
		void testDebayerFastY(void);
		void testDebayerFastU(void);
		void testDebayerFastV(void);
};

#endif
