#include "Hilaris.h"

int main()
{
	// Create a Hilaris instance
	Hilaris hilaris;
	
	// Get a Camera with a buffer size of 2.
	Camera *camera = hilaris.getCamera(2);
	
	return 0;
}
