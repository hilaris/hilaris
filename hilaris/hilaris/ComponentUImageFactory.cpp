#include "ComponentUImageFactory.h"

ComponentUImage ComponentUImageFactory::getFastDebayered(RawImage* raw)
{
	ComponentUImage image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	OscVisFastDebayerChromU(&raw->getOscarContext(), &image.getOscarContext());
	
	return image;
}
