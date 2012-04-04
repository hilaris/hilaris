#ifndef _DEBAYER_H_
#define _DEBAYER_H_

class Debayer
{
	public:
		virtual Image* debayer(RawImage* raw) = 0;
};

#endif
