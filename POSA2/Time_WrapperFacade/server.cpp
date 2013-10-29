#include<time.h>
#include<stdio.h>
#include<string.h>

#include "InetAddr_WF.h"
#include "SockStream_WF.h"
#include "SockAcceptor_WF.h"

#define MAXLINE 1024

int main(int argc, char **argv)
{
	char buff[MAXLINE];
	time_t ticks;

	Inet_Addr addr(80, INADDR_ANY);/* Init the Address struct */
	SOCK_Acceptor acc(addr);/* Accept connection */
	
	for(;;){
		SOCK_Stream *s = new SOCK_Stream();
		acc.Accept(*s);
		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "<html><body>%.24s\r\n</body></html>", ctime(&ticks));
		s->send(buff, strlen(buff), 0);
		
		//s->recv(buff, MAXLINE, 0);
		//printf("%s", buff);
		delete s;
	}

	return 0;
}
