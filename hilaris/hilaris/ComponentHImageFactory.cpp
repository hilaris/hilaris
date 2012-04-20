#include "ComponentHImageFactory.h"

ComponentHImage ComponentHImageFactory::getFastDebayered(RawImage* raw)
{
	ComponentHImage image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	OscVisFastDebayerHSL_H(&raw->getOscarContext(), &image.getOscarContext());
	
	return image;
}
