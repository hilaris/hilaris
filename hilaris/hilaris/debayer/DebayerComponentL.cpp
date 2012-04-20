#include "DebayerComponentL.h"

EnOscPictureType DebayerComponentL::getType()
{
	return OSC_PICTURE_HUE;
}

long unsigned int DebayerComponentL::getSize()
{
	return sizeof(ComponentLImage);
}

ComponentLImage* DebayerComponentL::getObject(uint16 width, uint16 height)
{
	return new ComponentLImage(width, height);
}

bool DebayerComponentL::debayer(RawImage* raw, Image* image)
{
	ComponentLImage b = ComponentLImageFactory::getFastDebayered(raw);
	
	memcpy(image, &b, sizeof(b));
	
	return true;
}
