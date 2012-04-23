#include "Histogram.h"

Histogram::Histogram(GreyscaleImage* grey)
{
	this->image = grey;
}

void Histogram::init(void)
{
	// initialize data provider
	for(int k = 0; k <= 255; k++)
	{
		this->value(k) = 0;
	}
	
	for(int i = 0; i < this->image->getHeight(); i++)
	{
		for(int j = 0; j < this->image->getWidth(); j++)
		{
			int tval = this->image->pixel(i, j);
			
			this->value(tval) = (int)(this->value(tval) + 1);
		}
	}
}

void Histogram::equalize(void)
{
	// get minimal cdf
	int cdfMin = 0;
	for(int k = 0; k <= 255; k ++)
	{
		if(this->value(k) > 0)
		{
			cdfMin = this->value(k);
			break;
		}
	}
	
	int dimensions = this->image->getWidth() * this->image->getHeight();
	
	for(int i = 0; i < this->image->getHeight(); i++)
	{
		for(int j = 0; j < this->image->getWidth(); j++)
		{			
			int ans = (int)floor(((this->cdf(this->image->pixel(i, j)) - cdfMin) / (float)(dimensions - cdfMin)) * 255 + 0.5);
			
			this->image->pixel(i, j) = ans;
			
		}
	}
}

int& Histogram::value(int key)
{
	return this->data[key];
}

int Histogram::cdf(int key)
{
	int res = 0;
	
	for(int i = 0; i <= key; i++)
	{
		res += this->value(i);
	}
	
	return res;
}
