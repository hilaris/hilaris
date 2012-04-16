#include "Hilaris.h"

int main()
{
	// Create a binary image.
	BinaryImage binary = BinaryImageFactory::create(100, 100, 0);
	
	// Make it a BGRImage.
	BGRImage bgr = BGRImageFactory::getFromBinaryImage(binary);
	
	return 0;
}
