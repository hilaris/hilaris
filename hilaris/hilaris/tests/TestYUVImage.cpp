#include <cppunit/extensions/HelperMacros.h>

#include "TestYUVImage.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestYUVImage);

void TestYUVImage::tearDown(void)
{
	getHilaris().resetCamera();
}

void TestYUVImage::testDebayerFast()
{
	getHilaris().resetCamera();
	Camera* camera = getHilaris().getCamera(new DebayerYUV422Fast());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	YUV422Image* image = (YUV422Image*)camera->captureImage();
		
	CPPUNIT_ASSERT(image->getHeight() == (height / 2));
	CPPUNIT_ASSERT(image->getWidth()  == (width  / 2));
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_YUV_422);
}

void TestYUVImage::testDebayerFastY()
{
	getHilaris().resetCamera();
	Camera* camera = getHilaris().getCamera(new DebayerComponentY());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	ComponentYImage* image = (ComponentYImage*)camera->captureImage();
	
	CPPUNIT_ASSERT(image->getHeight() == (height / 2));
	CPPUNIT_ASSERT(image->getWidth()  == (width  / 2));
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_GREYSCALE);
}

void TestYUVImage::testDebayerFastU()
{
	getHilaris().resetCamera();
	Camera* camera = getHilaris().getCamera(new DebayerComponentU());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	ComponentUImage* image = (ComponentUImage*)camera->captureImage();
	
	CPPUNIT_ASSERT(image->getHeight() == (height / 2));
	CPPUNIT_ASSERT(image->getWidth()  == (width  / 2));
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_CHROM_U);
}

void TestYUVImage::testDebayerFastV()
{
	getHilaris().resetCamera();
	Camera* camera = getHilaris().getCamera(new DebayerComponentV());
	
	uint16 height = camera->getHeight();
	uint16 width  = camera->getWidth();
	
	// capture image
	ComponentVImage* image = (ComponentVImage*)camera->captureImage();
	
	CPPUNIT_ASSERT(image->getHeight() == (height / 2));
	CPPUNIT_ASSERT(image->getWidth()  == (width  / 2));
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_CHROM_V);
}
