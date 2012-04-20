#include "ComponentVImageFactory.h"

ComponentVImage ComponentVImageFactory::getFastDebayered(RawImage* raw)
{
	ComponentVImage image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	OscVisFastDebayerChromV(&raw->getOscarContext(), &image.getOscarContext());
	
	return image;
}
