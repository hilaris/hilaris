#ifndef _COMPONENT_Y_IMAGE_FACTORY_
#define _COMPONENT_Y_IMAGE_FACTORY_

#include "oscar.h"
#include "ComponentYImage.h"
#include "RawImage.h"

class ComponentYImageFactory
{
	public:
		static ComponentYImage getFastDebayered(RawImage* raw);
};

#endif
