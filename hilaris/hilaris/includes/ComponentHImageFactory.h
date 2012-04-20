#ifndef _COMPONENT_H_IMAGE_FACTORY_
#define _COMPONENT_H_IMAGE_FACTORY_

#include "oscar.h"
#include "ComponentHImage.h"
#include "RawImage.h"

class ComponentHImageFactory
{
	public:
		static ComponentHImage getFastDebayered(RawImage* raw);
};

#endif
