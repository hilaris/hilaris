#ifndef _STREAM_SERVER_H_
#define _STREAM_SERVER_H_

class StreamServer {
	public:
		bool listen();
		bool accept();
		int send();
		int recieve();
		bool stop();
	private:
};

#endif 
