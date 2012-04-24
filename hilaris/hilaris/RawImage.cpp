#include "RawImage.h"

RawImage::RawImage(uint16 width, uint16 height)
{
	this->width = width;
	this->height = height;
}

uint8* RawImage::getDataPtr()
{
	return this->data;
}

EnOscPictureType RawImage::getType()
{
	// strunzwurscht
	return OSC_PICTURE_BGR_24;;
}

bool RawImage::debayerFast(GreyscaleImage* image)
{
	return OscVisFastDebayerGrey(&this->getOscarContext(), &image->getOscarContext()) == SUCCESS;
}

bool RawImage::debayerVector(GreyscaleImage* image)
{
	return (OscVisVectorDebayerGrey(&this->getOscarContext(), &image->getOscarContext()) == SUCCESS);
}

bool RawImage::debayerHalfsize(GreyscaleImage* image)
{	
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order, 0, 0);
	
	return (OscVisDebayerGreyscaleHalfSize(this->getDataPtr(), this->getWidth(), this->getHeight(), order, image->getDataPtr()) == SUCCESS);
}

bool RawImage::debayerFast(BGRImage* image)
{
	return OscVisFastDebayerBGR(&this->getOscarContext(), &image->getOscarContext()) == SUCCESS;
}

bool RawImage::debayerBilinear(BGRImage* image)
{
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order, 0, 0);
	
	uint8 pTemp[this->getWidth() * 4];
	
	return (OscVisDebayerBilinearBGR(image->getDataPtr(), this->getDataPtr(), this->getWidth(), this->getHeight(), pTemp, order) == SUCCESS);
}

bool RawImage::debayerStandard(BGRImage* image)
{
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order, 0, 0);
	
	return (OscVisDebayer(this->getDataPtr(), this->getWidth(), this->getHeight(), order, image->getDataPtr()) == SUCCESS);	
}

bool RawImage::debayerHalfsize(BGRImage* image)
{
	enum EnBayerOrder order;
	OscCamGetBayerOrder(&order, 0, 0);
	
	return (OscVisDebayerHalfSize(this->getDataPtr(), this->getWidth(), this->getHeight(), order, image->getDataPtr()) == SUCCESS);
}


bool RawImage::debayerFast(RGBImage* image)
{
	return OscVisFastDebayerRGB(&this->getOscarContext(), &image->getOscarContext());
}

bool RawImage::debayerFast(ComponentHImage* image)
{
	return (OscVisFastDebayerHSL_H(&this->getOscarContext(), &image->getOscarContext()) == SUCCESS);
}

bool RawImage::debayerFast(ComponentSImage* image)
{
	return (OscVisFastDebayerHSL_S(&this->getOscarContext(), &image->getOscarContext()) == SUCCESS);
}

bool RawImage::debayerFast(ComponentLImage* image)
{
	return (OscVisFastDebayerHSL_L(&this->getOscarContext(), &image->getOscarContext()) == SUCCESS);
}

bool RawImage::debayerFast(ComponentYImage* image)
{
	return (OscVisFastDebayerLumY(&this->getOscarContext(), &image->getOscarContext()) == SUCCESS);
}

bool RawImage::debayerFast(ComponentUImage* image)
{
	return (OscVisFastDebayerChromU(&this->getOscarContext(), &image->getOscarContext()) == SUCCESS);
}

bool RawImage::debayerFast(ComponentVImage* image)
{
	return (OscVisFastDebayerChromV(&this->getOscarContext(), &image->getOscarContext()) == SUCCESS);
}

bool RawImage::debayerFast(YUV422Image* image)
{
	return (OscVisFastDebayerYUV422(&this->getOscarContext(), &image->getOscarContext()) == SUCCESS);
}


