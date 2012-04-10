#include <cppunit/extensions/HelperMacros.h>

#include "Hilaris.h"
#include "TestBGRImage.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestBGRImage);

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
