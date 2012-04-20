#ifndef _TESTCAMERA_H_
#define _TESTCAMERA_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

extern Hilaris& getHilaris();

class TestCamera : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestCamera);
	
		CPPUNIT_TEST(testStandardConstructor);
		CPPUNIT_TEST(testShutterWidth);
		CPPUNIT_TEST(testBlackLevelOffset);
		CPPUNIT_TEST(testPresetRegisters);
		CPPUNIT_TEST(testDefaultDebayer);
		
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void) {}
		void tearDown(void);

		void testStandardConstructor(void);
		void testShutterWidth(void);
		void testBlackLevelOffset(void);
		void testPresetRegisters(void);
		void testDefaultDebayer(void);
};

#endif
