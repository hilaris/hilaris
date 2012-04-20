#include "ComponentLImageFactory.h"

ComponentLImage ComponentLImageFactory::getFastDebayered(RawImage* raw)
{
	ComponentLImage image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	OscVisFastDebayerHSL_L(&raw->getOscarContext(), &image.getOscarContext());
	
	return image;
}
