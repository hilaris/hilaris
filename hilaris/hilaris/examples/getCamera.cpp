#include "Hilaris.h"

int main()
{
	// Create a Hilaris instance
	Hilaris hilaris;
	
	// Get a Camera instance from Hilaris
	Camera *camera = hilaris.getCamera();
	
	return 0;
}
