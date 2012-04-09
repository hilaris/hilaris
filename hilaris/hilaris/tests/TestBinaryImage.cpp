#include <cppunit/extensions/HelperMacros.h>

#include "Hilaris.h"
#include "BinaryImageFactory.h"
#include "TestBinaryImage.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestBinaryImage);

void TestBinaryImage::testCreate(void)
{
	uint16 width  = 32;
	uint16 height = 32;
	bool loopTest = true;
	
	// create an image with a random value (123), and test wheter just 0 and 1 will be stored
	BinaryImage image = BinaryImageFactory::create(width, height, 123);
	
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
