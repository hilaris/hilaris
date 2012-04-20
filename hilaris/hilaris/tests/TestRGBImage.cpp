#include <cppunit/extensions/HelperMacros.h>

#include "Hilaris.h"
#include "TestRGBImage.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestRGBImage);

void TestRGBImage::tearDown(void)
{
	getHilaris().resetCamera();
}

void TestRGBImage::testCreate(void)
{
	uint16 width  = 32;
	uint16 height = 32;
	bool loopTest = true;
	
	// create a red image
	RGBImage image = RGBImageFactory::create(width, height, 0, 0, 255);
	
	CPPUNIT_ASSERT(image.getWidth() == width);
	CPPUNIT_ASSERT(image.getHeight() == height);
	
	for(int i = 0; i < image.getHeight(); i++)
	{
		for(int j = 0; j < image.getWidth(); j++)
		{
			loopTest = loopTest && (image(i, j, RGBImage::BLUE ) == 0);
			loopTest = loopTest && (image(i, j, RGBImage::GREEN) == 0);
			loopTest = loopTest && (image(i, j, RGBImage::RED  ) == 255);
		}
	}
	
	CPPUNIT_ASSERT(loopTest);
}

void TestRGBImage::testDebayerFast()
{
	Camera* camera = getHilaris().getCamera(new DebayerRGBStandard());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	RGBImage* image = (RGBImage*)camera->captureImage();
	
	CPPUNIT_ASSERT(image->getHeight() == (height / 2));
	CPPUNIT_ASSERT(image->getWidth()  == (width  / 2));
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_RGB_24);
}
