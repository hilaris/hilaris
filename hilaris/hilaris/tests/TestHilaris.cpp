#include <cppunit/extensions/HelperMacros.h>

#include "Hilaris.h"
#include "TestHilaris.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestHilaris);

void TestHilaris::testStartUp(void)
{
	Hilaris hilaris;
	
	hilaris.setFileLogLevel(NONE);
	hilaris.setConsoleLogLevel(NONE);
	
	CPPUNIT_ASSERT(hilaris.loaded());

}
