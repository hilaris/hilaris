#include "Hilaris.h"
#include "TestHilaris.h"

#include "HilarisOutputter.h"
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>

int main(void)
{
	// Get the top level suite from the registry
	CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

	// Adds the test to the list of test to run
	// CppUnit::TextUi::TestRunner runner;
	CppUnit::TextTestRunner runner;
	runner.addTest(suite);

	// Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CppUnit::HilarisOutputter(&runner.result(),std::cerr));
	
	// Run the tests.
	bool wasSucessful = runner.run();

	// Return error code 1 if the one of test failed.
	return wasSucessful ? 0 : 1;
}
