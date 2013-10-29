#ifndef _TIME_ACCEPTOR_H_
#define _TIME_ACCEPTOR_H_

#include "Event_Type.h"
#include "InetAddr_WF.h"
#include "SockAcceptor_WF.h"

class Time_Acceptor : public Event_Handler{
	public:
		//Register the listen socket event
		Time_Acceptor(const Inet_Addr &addr,Reactor *reactor):
			acceptor_(SOCK_Acceptor(addr)), reactor_(reactor){
				reactor_->register_handler(this, READ_EVENT);
		}
		//Deal with accept event
		virtual void handle_event (HANDLE h, Event_Type event_type) 
		{
			if(event_type == READ_EVENT) {
				SOCK_Stream *client_connection = new SOCK_Stream();
				//Accept the connection
				acceptor_.Accept(*client_connection);
				//create and register new handle
				Time_Handler *handler = new
					Time_Handler(client_connection, reactor_);
			}
		}
		//get the handle
		virtual HANDLE get_handle () const {
			return acceptor_.get_handle();
		}

	private:
		SOCK_Acceptor acceptor_;
		Reactor *reactor_;
};

#endif
