#ifndef _STREAM_CLIENT_H_
#define _STREAM_CLIENT_H_

class StreamClinet {
	public:
		bool connect(char* ip, uint16 port);
		bool disconnect(); 
		int send();
		int recieve();
};

#endif 
