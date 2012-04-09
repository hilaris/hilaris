#include <cppunit/extensions/HelperMacros.h>

#include "Hilaris.h"
#include "GreyscaleImageFactory.h"
#include "TestGreyscaleImage.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestGreyscaleImage);

void TestGreyscaleImage::testCreate(void)
{
	uint16 width  = 32;
	uint16 height = 32;
	bool loopTest = true;
	
	GreyscaleImage image = GreyscaleImageFactory::create(width, height, 127);
	
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
