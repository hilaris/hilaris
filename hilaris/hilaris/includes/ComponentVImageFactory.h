#ifndef _COMPONENT_V_IMAGE_FACTORY_
#define _COMPONENT_V_IMAGE_FACTORY_

#include "oscar.h"
#include "ComponentVImage.h"
#include "RawImage.h"

class ComponentVImageFactory
{
	public:
		static ComponentVImage getFastDebayered(RawImage* raw);
};

#endif
