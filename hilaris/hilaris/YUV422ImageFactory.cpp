#include "YUV422ImageFactory.h"

YUV422Image YUV422ImageFactory::getFastDebayered(RawImage* raw)
{
	YUV422Image image(raw->getWidth() / 2, raw->getHeight() / 2);
	
	OscVisFastDebayerYUV422(&raw->getOscarContext(), &image.getOscarContext());
	
	return image;
}
