#ifndef _HILARIS_H_
#define _HILARIS_H_

#include "oscar.h"

class Hilaris {
	public:
		Hilaris();
		void setFrameBufferSize(int size);
		void setConsoleLogLevel(const enum EnOscLogLevel level) const;
		void setFileLogLevel(const enum EnOscLogLevel level) const;
		Camera* getCamera();
		
		bool getFrameBufferSize();
		bool loaded();
		
	private:
		int loadSuccess;
		int frameBufferSize;
		
		Camera* camera = NULL;
};

#endif 
