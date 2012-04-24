#ifndef _TESTHSLIMAGE_H_
#define _TESTHSLIMAGE_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

extern Hilaris& getHilaris();

class TestHSLImage : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestHSLImage);
	
		CPPUNIT_TEST(testDebayerFastH);
		CPPUNIT_TEST(testDebayerFastS);
		CPPUNIT_TEST(testDebayerFastL);
		
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void) {}
		void tearDown(void);

		void testDebayerFastH(void);
		void testDebayerFastS(void);
		void testDebayerFastL(void);
};

#endif
