#ifndef _COMPONENT_U_IMAGE_FACTORY_
#define _COMPONENT_U_IMAGE_FACTORY_

#include "oscar.h"
#include "ComponentUImage.h"
#include "RawImage.h"

class ComponentUImageFactory
{
	public:
		static ComponentUImage getFastDebayered(RawImage* raw);
};

#endif
