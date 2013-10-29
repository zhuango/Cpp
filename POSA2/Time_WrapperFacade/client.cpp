#include<stdio.h>
#include<stdlib.h>

#include "Inet_AddrClient.h"
#include "SockConnect.h"
#include "SockStream_WF.h"

#define MAXLINE 1024

int main(int argc, char **argv)
{
	char *buf[MAXLINE];
	int n;
	if(argc != 2){
		printf("Usage: %s <IPAddress>\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	Inet_AddrClient addr(80, argv[1]);
	SOCK_Connect conn;
	SOCK_Stream stream;
	
	stream.set_handle(conn.Connect(addr));
	n = stream.recv(buf, MAXLINE, 0);
	stream.Close();

	buf[n] = '\0';
	printf("%s", buf);
	
	return 0;
}
