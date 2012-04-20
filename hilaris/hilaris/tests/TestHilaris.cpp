#include <cppunit/extensions/HelperMacros.h>

#include "Hilaris.h"
#include "HilarisGlobal.h"
#include "TestHilaris.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestHilaris);

void TestHilaris::tearDown(void)
{
	getHilaris().resetCamera();
}

void TestHilaris::testStartUp(void)
{
	CPPUNIT_ASSERT(getHilaris().loaded());
}
