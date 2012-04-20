#include "ComponentYImageFactory.h"

ComponentYImage ComponentYImageFactory::getFastDebayered(RawImage* raw)
{
	ComponentYImage image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	OscVisFastDebayerLumY(&raw->getOscarContext(), &image.getOscarContext());
	
	return image;
}
