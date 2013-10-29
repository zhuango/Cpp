#ifndef _REACTOR_IMPLEMENTATION_
#define _REACTOR_IMPLEMENTATION_

typedef int HANDLE;

class Reactor_Implementation{
	public:
		//register handler and event on this handler
		virtual void register_handler
			(Event_Handler *eh, Event_Type et) = 0;

//		virtual void register_handler
//			(HANDLE h, Event_Handler *eh, Event_Type et) = 0;

		virtual void remove_handler
			(Event_Handler *eh, Event_Type et) = 0;

//		virtual void remove_handler
//			(HANDLE h, Event_Type et) = 0;

		
	//	void handle_events(Time_Value *timeout = 0);
		virtual void handle_events() = 0;//wait for handlers' events (select or poll or ...)

};

#endif
