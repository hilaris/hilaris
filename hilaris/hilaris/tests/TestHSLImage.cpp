#include <cppunit/extensions/HelperMacros.h>

#include "TestHSLImage.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestHSLImage);

void TestHSLImage::tearDown(void)
{
	getHilaris().resetCamera();
}

void TestHSLImage::testDebayerFastH()
{
	getHilaris().resetCamera();
	Camera* camera = getHilaris().getCamera(new DebayerComponentH());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	ComponentHImage* image = (ComponentHImage*)camera->captureImage();
	
	CPPUNIT_ASSERT(image->getHeight() == (height / 2));
	CPPUNIT_ASSERT(image->getWidth()  == (width  / 2));
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_HUE);
}

void TestHSLImage::testDebayerFastS()
{
	getHilaris().resetCamera();
	Camera* camera = getHilaris().getCamera(new DebayerComponentS());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	ComponentSImage* image = (ComponentSImage*)camera->captureImage();
	
	CPPUNIT_ASSERT(image->getHeight() == (height / 2));
	CPPUNIT_ASSERT(image->getWidth()  == (width  / 2));
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_HUE);
}

void TestHSLImage::testDebayerFastL()
{
	getHilaris().resetCamera();
	Camera* camera = getHilaris().getCamera(new DebayerComponentL());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	ComponentLImage* image = (ComponentLImage*)camera->captureImage();
	
	CPPUNIT_ASSERT(image->getHeight() == (height / 2));
	CPPUNIT_ASSERT(image->getWidth()  == (width  / 2));
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_HUE);
}
