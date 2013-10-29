server:server.cpp InetAddr_WF.h SockAcceptor_WF.h SockStream_WF.h
	g++ server.cpp -o server

client:client.cpp Inet_AddrClient.h SockConnect.h SockStream_WF.h
	g++ client.cpp -o client
.PHONY:clean
clean:	
	rm server client
