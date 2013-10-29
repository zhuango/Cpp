#ifndef _InetAddr_WrapperFacade_H_
#define _InetAddr_WrapperFacade_H_
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h>

class Inet_Addr{
	public:
		/* Init the address struct */
		Inet_Addr(short port, long addr){
			bzero(&addr_, sizeof(addr_));
			addr_.sin_family = AF_INET;
			addr_.sin_port = htons(port);
			addr_.sin_addr.s_addr = htonl(addr);
		}
		/* Get the port for host */
		short get_port() const
		{ return ntohs(addr_.sin_port);}
		
		/* Get the address for host */
		long get_addr() const
		{ return ntohl(addr_.sin_addr.s_addr);}
		
		/* Get the sockaddr struct */
		sockaddr *addr() const
		{ return (struct sockaddr *)&addr_;}
		
		/* Get the size of address size */
		size_t size()const
		{ return sizeof(addr_);}

	private:
		/* Address struct */
		sockaddr_in addr_;
};

#endif
