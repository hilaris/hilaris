#ifndef _TESTBINARYIMAGE_H_
#define _TESTBINARYIMAGE_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class TestBinaryImage : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestBinaryImage);
	
		CPPUNIT_TEST(testCreate);
		CPPUNIT_TEST(invert);
		CPPUNIT_TEST(testSubstract);
		
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void) {}
		void tearDown(void) {}

		void testCreate(void);
		void invert(void);
		void testSubstract(void);
};

#endif
