#ifndef _SOCKCONNECT_H_
#define _SOCKCONNECT_H_
#include<sys/socket.h>

typedef int SOCKET;

class SOCK_Connect{
	private:
		SOCKET socket_;
	public:
		SOCK_Connect(){
			socket_ = socket(AF_INET, SOCK_STREAM, 0);
		}

		SOCKET Connect(Inet_AddrClient &addr){
			connect(socket_, addr.addr(), addr.size());
			return socket_;
		}
};
#endif
