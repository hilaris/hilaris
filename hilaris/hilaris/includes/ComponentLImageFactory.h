#ifndef _COMPONENT_L_IMAGE_FACTORY_
#define _COMPONENT_L_IMAGE_FACTORY_

#include "oscar.h"
#include "ComponentLImage.h"
#include "RawImage.h"

class ComponentLImageFactory
{
	public:
		static ComponentLImage getFastDebayered(RawImage* raw);
};

#endif
