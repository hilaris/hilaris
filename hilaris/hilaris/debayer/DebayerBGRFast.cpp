#include "DebayerBGRFast.h"
#include <string.h>


bool DebayerBGRFast::debayer(RawImage* raw, Image* image)
{
	BGRImage b = BGRImageFactory::getFastDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	
	return true;
}
