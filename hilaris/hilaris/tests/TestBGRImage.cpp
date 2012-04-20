#include <cppunit/extensions/HelperMacros.h>

#include "Hilaris.h"
#include "TestBGRImage.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestBGRImage);

void TestBGRImage::tearDown(void)
{
	getHilaris().resetCamera();
}

void TestBGRImage::testCreate(void)
{
	uint16 width  = 32;
	uint16 height = 32;
	bool loopTest = true;
	
	// create a red image
	BGRImage image = BGRImageFactory::create(width, height, 0, 0, 255);
	
	CPPUNIT_ASSERT(image.getWidth() == width);
	CPPUNIT_ASSERT(image.getHeight() == height);
	
	for(int i = 0; i < image.getHeight(); i++)
	{
		for(int j = 0; j < image.getWidth(); j++)
		{
			loopTest = loopTest && (image(i, j, BGRImage::BLUE ) == 0);
			loopTest = loopTest && (image(i, j, BGRImage::GREEN) == 0);
			loopTest = loopTest && (image(i, j, BGRImage::RED  ) == 255);
		}
	}
	
	CPPUNIT_ASSERT(loopTest);
}

void TestBGRImage::testDebayerFast()
{
	Camera* camera = getHilaris().getCamera(new DebayerBGRFast());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	BGRImage* image = (BGRImage*)camera->captureImage();
	
	CPPUNIT_ASSERT(image->getHeight() == (height / 2));
	CPPUNIT_ASSERT(image->getWidth()  == (width  / 2));
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_BGR_24);
	
	getHilaris().resetCamera();
}

void TestBGRImage::testDebayerBilinear()
{
	Camera* camera = getHilaris().getCamera(new DebayerBGRBilinear());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	BGRImage* image = (BGRImage*)camera->captureImage();
	
	CPPUNIT_ASSERT(image->getHeight() == height);
	CPPUNIT_ASSERT(image->getWidth()  == width);
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_BGR_24);
	
	getHilaris().resetCamera();
}

void TestBGRImage::testDebayerHalfsize()
{
	Camera* camera = getHilaris().getCamera(new DebayerBGRHalfsize());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	BGRImage* image = (BGRImage*)camera->captureImage();
	
	CPPUNIT_ASSERT(image->getHeight() == (height / 2));
	CPPUNIT_ASSERT(image->getWidth()  == (width  / 2));
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_BGR_24);
	
	getHilaris().resetCamera();
}

void TestBGRImage::testDebayerStandard()
{
	Camera* camera = getHilaris().getCamera(new DebayerBGRStandard());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	BGRImage* image = (BGRImage*)camera->captureImage();
		
	CPPUNIT_ASSERT(image->getHeight() == height);
	CPPUNIT_ASSERT(image->getWidth()  == width);
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_BGR_24);
	
	getHilaris().resetCamera();
}
