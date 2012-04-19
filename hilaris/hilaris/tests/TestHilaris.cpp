#include <cppunit/extensions/HelperMacros.h>

#include "Hilaris.h"
#include "HilarisGlobal.h"
#include "TestHilaris.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestHilaris);

void TestHilaris::setUp(void)
{
	// set up hilaris
	getHilaris().setFileLogLevel(NONE);
	getHilaris().setConsoleLogLevel(NONE);
}

void TestHilaris::testStartUp(void)
{
	CPPUNIT_ASSERT(getHilaris().loaded());
}

void TestHilaris::tearDown(void)
{

}
