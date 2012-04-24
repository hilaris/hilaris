#include <cppunit/extensions/HelperMacros.h>

#include "Hilaris.h"
#include "TestGreyscaleImage.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestGreyscaleImage);

void TestGreyscaleImage::tearDown(void)
{
	getHilaris().resetCamera();
}

void TestGreyscaleImage::testCreate(void)
{
	uint16 width  = 32;
	uint16 height = 32;
	bool loopTest = true;
	
	GreyscaleImage image(width, height, 127);
	
	CPPUNIT_ASSERT(image.getWidth() == width);
	CPPUNIT_ASSERT(image.getHeight() == height);
	
	for(int i = 0; i < image.getHeight(); i++)
	{
		for(int j = 0; j < image.getWidth(); j++)
		{
			loopTest = loopTest && (image(i, j) == 127);
		}
	}
	
	CPPUNIT_ASSERT(loopTest);
}

void TestGreyscaleImage::testDebayerFast(void)
{
	Camera* camera = getHilaris().getCamera(new DebayerGreyscaleFast());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	GreyscaleImage* image = (GreyscaleImage*)camera->captureImage();
	
	CPPUNIT_ASSERT(image->getHeight() == (height / 2));
	CPPUNIT_ASSERT(image->getWidth()  == (width  / 2));
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_GREYSCALE);
}

void TestGreyscaleImage::testDebayerHalfsize(void)
{
	Camera* camera = getHilaris().getCamera(new DebayerGreyscaleHalfsize());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	GreyscaleImage* image = (GreyscaleImage*)camera->captureImage();
	
	CPPUNIT_ASSERT(image->getHeight() == (height / 2));
	CPPUNIT_ASSERT(image->getWidth()  == (width  / 2));
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_GREYSCALE);
}

void TestGreyscaleImage::testDebayerVector(void)
{
	Camera* camera = getHilaris().getCamera(new DebayerGreyscaleVector());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	GreyscaleImage* image = (GreyscaleImage*)camera->captureImage();
	
	CPPUNIT_ASSERT(image->getHeight() == (height / 2));
	CPPUNIT_ASSERT(image->getWidth()  == (width  / 2));
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_GREYSCALE);
}
