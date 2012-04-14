#include "Hilaris.h"

int main()
{
	// Create a Hilaris instance
	Hilaris hilaris;
	
	// Get a Camera for greyscale images.
	Camera *camera = hilaris.getCamera(new DebayerGreyscaleFast());
	
	return 0;
}
