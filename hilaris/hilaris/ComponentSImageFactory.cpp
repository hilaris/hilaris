#include "ComponentSImageFactory.h"

ComponentSImage ComponentSImageFactory::getFastDebayered(RawImage* raw)
{
	ComponentSImage image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	OscVisFastDebayerHSL_S(&raw->getOscarContext(), &image.getOscarContext());
	
	return image;
}
