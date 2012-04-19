#include <cppunit/extensions/HelperMacros.h>

#include "Hilaris.h"
#include "TestCamera.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestCamera);

void TestCamera::setUp(void)
{
	// set up hilaris
	getHilaris().setFileLogLevel(NONE);
	getHilaris().setConsoleLogLevel(NONE);
}

void TestCamera::testStandardConstructor(void)
{
	// using standard debayer
	Camera* camera = getHilaris().getCamera();
	
	// test image width and height
	CPPUNIT_ASSERT(camera->getHeight() == Image::MAX_HEIGHT);
	CPPUNIT_ASSERT(camera->getWidth()  == Image::MAX_WIDTH);
	
	BGRImage* image = (BGRImage*)camera->captureImage();
	
	// default debayer reduces the image size
	CPPUNIT_ASSERT(image->getHeight() == Image::MAX_HEIGHT / 2);
	CPPUNIT_ASSERT(image->getWidth()  == Image::MAX_WIDTH  / 2);
}

void TestCamera::tearDown(void)
{
	
}
