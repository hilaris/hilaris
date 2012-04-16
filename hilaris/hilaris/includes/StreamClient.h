#ifndef _STREAM_CLIENT_H_
#define _STREAM_CLIENT_H_

#include "Hilaris.h"

/**
 *  @brief A Streaming Client.
 *
 *  @author Jim Schmid
 *  @author Michael Kreis
 *
 *  @version 1.0
 *  @since March 2012
 */
class StreamClient {
	public:
		/**
		 *  @brief Connect to a specific IP-Address with a given Port.
		 *  @return Success status.
		 */
		bool connect(char* ip, int port);
		
		/**
		 *  @brief Disconnect from a server.
		 *  @return Success status.
		 */
		bool disconnect();
		
		/**
		 *  @brief Send
		 *  @return Int
		 *  @todo wtf?
		 */
		int send();
		
		/**
		 *  @brief Recieve
		 *  @return Int
		 *  @todo wtf?
		 */
		int recieve();
};

#endif 
