#include <cppunit/extensions/HelperMacros.h>

#include "TestBinaryImage.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestBinaryImage);

void TestBinaryImage::setUp(void)
{
	// ...
}

void TestBinaryImage::tearDown(void)
{
	getHilaris().resetCamera();
}

void TestBinaryImage::testCreate(void)
{
	uint16 width  = 32;
	uint16 height = 32;
	bool loopTest = true;
	
	// create an image with a random value (123), and test wheter just 0 and 1 will be stored
	BinaryImage image(width, height, 123);
	
	CPPUNIT_ASSERT(image.getWidth() == width);
	CPPUNIT_ASSERT(image.getHeight() == height);
	
	for(int i = 0; i < image.getHeight(); i++)
	{
		for(int j = 0; j < image.getWidth(); j++)
		{
			loopTest = loopTest && (image(i, j) == 1);
		}
	}
	
	CPPUNIT_ASSERT(loopTest);
}

void TestBinaryImage::testDirectDebayer(void)
{
	// using direct debayer
	Camera* camera = getHilaris().getCamera(new DebayerBinaryDirect());
	
	BinaryImage* image = (BinaryImage*)camera->captureImage();
	
	CPPUNIT_ASSERT(image->getWidth()  == Image::MAX_WIDTH  / 2);
	CPPUNIT_ASSERT(image->getHeight() == Image::MAX_HEIGHT / 2);
	CPPUNIT_ASSERT(image->getType()   == OSC_PICTURE_BINARY);
}

void TestBinaryImage::invert(void)
{
	uint16 width  = 4;
	uint16 height = 4;
	
	BinaryImage binary(width, height, 0);
	
	binary(0, 0) = 0;
	binary(0, 1) = 1;
	binary(1, 0) = 0;
	binary(1, 1) = 1;
	
	binary.invert();
	
	CPPUNIT_ASSERT(binary(0, 0) == 1);
	CPPUNIT_ASSERT(binary(0, 1) == 0);
	CPPUNIT_ASSERT(binary(1, 0) == 1);
	CPPUNIT_ASSERT(binary(1, 1) == 0);
	
}

void TestBinaryImage::testSubstract(void)
{
	uint16 width  = 4;
	uint16 height = 4;
	
	BinaryImage one(width, height, 0);
	BinaryImage two(width, height, 1);
	
	/*
		setup images
		
		one: -----  two: -----  res: -----
		     |0|0|       |1|0|       |1|0|
		     -----       -----       -----
		     |1|0|       |0|1|       |1|1|
		     -----       -----       -----
	*/
	
	one(0, 0) = 0;
	one(0, 1) = 0;
	one(1, 0) = 1;
	one(1, 1) = 0;
	
	two(0, 0) = 1;
	two(0, 1) = 0;
	two(1, 0) = 0;
	two(1, 1) = 1;
	
	BinaryImage res = one - two;
	
	CPPUNIT_ASSERT(res(0, 0) == 1);
	CPPUNIT_ASSERT(res(0, 1) == 0);
	CPPUNIT_ASSERT(res(1, 0) == 1);
	CPPUNIT_ASSERT(res(1, 1) == 1);
}
