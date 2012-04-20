#ifndef _COMPONENT_S_IMAGE_FACTORY_
#define _COMPONENT_S_IMAGE_FACTORY_

#include "oscar.h"
#include "ComponentSImage.h"
#include "RawImage.h"

class ComponentSImageFactory
{
	public:
		static ComponentSImage getFastDebayered(RawImage* raw);
};

#endif
