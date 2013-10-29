#ifndef _INETADDRCLIENT_H_
#define _INETADDRCLIENT_H_
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h>
#include<arpa/inet.h>

class Inet_AddrClient{
	private:
		sockaddr_in addr_;
	public:
		Inet_AddrClient(short port, const char *addr){
			bzero(&addr_, sizeof(addr_));
			addr_.sin_family = AF_INET;
			addr_.sin_port = htons(port);
			inet_pton(AF_INET, addr, &addr_.sin_addr.s_addr);
		}

		sockaddr *addr() const
		{return (struct sockaddr*)&addr_;}

		size_t size() const
		{return sizeof(addr_);}
};

#endif
