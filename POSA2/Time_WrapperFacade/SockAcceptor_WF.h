#ifndef _SOCKACCEPTOR_H_
#define _SOCKACCEPTOR_H_
typedef int SOCKET;
#include<sys/socket.h>

class SOCK_Acceptor{
	public:
		//Create the socket
		//Bind the interface
		//Listening
		SOCK_Acceptor(const Inet_Addr &addr){
			handle_ = socket(AF_INET, SOCK_STREAM, 0);
			bind(handle_, addr.addr(), addr.size());
			listen(handle_, 5);
		};
		//Accept and get connected socket,
		//give the connected socket to SOCK_Stream
		void Accept(SOCK_Stream &s){
			s.set_handle(accept(handle_, NULL, NULL));
		}

		void Setsockopt(int optname){
			int on = 1;
			setsockopt(handle_, AF_INET, optname, &on, sizeof(on));
		}

	private:
		//Listened socket
		SOCKET handle_;
};

#endif
