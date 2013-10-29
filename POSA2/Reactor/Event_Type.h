#ifndef _EVENT_TYPE_
#define _EVENT_TYPE_

typedef unsigned int Event_Type;

enum {
	READ_EVENT = 01,	//read evnet
	CLOSE_EVENT = 01,	//close event, same as read event
	ACCEPT_EVENT = 01,	//accept event, same as read event
	WRITE_EVENT = 02,	//write event
	SIGNAL_EVENT = 010	//signal event
};

#endif
