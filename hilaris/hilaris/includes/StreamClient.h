#ifndef _STREAM_CLIENT_H_
#define _STREAM_CLIENT_H_

#include "Hilaris.h"

class StreamClinet {
	public:
		bool connect(char* ip, int port);
		bool disconnect(); 
		int send();
		int recieve();
};

#endif 
