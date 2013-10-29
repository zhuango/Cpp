#include "head.h"

int main()
{
	//Set the portnumber and IPaddress
	Inet_Addr addr(80, INADDR_ANY);
	//Accept
	Time_Acceptor ta(addr, Reactor::instance());
	//Select
	for(;;){
		Reactor::instance()->handle_events();
	}
}
