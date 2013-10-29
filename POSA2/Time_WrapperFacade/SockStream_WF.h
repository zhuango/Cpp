#ifndef _SOCKS_WF_H_
#define _SOCKS_WF_H_
#include<unistd.h>
#include<fcntl.h>

typedef int SOCKET;

class SOCK_Stream{
	public:
		//Init connected socket
		SOCK_Stream() : handle_(-1) {}
		SOCK_Stream(SOCKET h) : handle_(h){}

		//Close connected socket
		~SOCK_Stream() {close(handle_);}

		//Set connected socket
		void set_handle (SOCKET h) {handle_ = h;}
		//Get connected socket
		SOCKET get_handle() const { return handle_;}

		//Send and Recv message
		ssize_t recv(void *buf, size_t len, int flags);
		ssize_t send(const char *buf, size_t len, int flags);
		void Close()
		{close(handle_);}
//		ssize_t recv_n(char *buf, size_t len, int flags);
//		ssize_t send_n(const char *buf, size_t len, int flags);

	private:
		SOCKET handle_;
};

//Send and Recv message
ssize_t SOCK_Stream::recv(void *buf, size_t len, int flags)
{
	int n;
	n = read(handle_, buf, len);

	return n;
}

ssize_t SOCK_Stream::send(const char *buf, size_t len, int flags)
{
	int n;
	n = write(handle_, buf, len);

	return n;
}
#endif
