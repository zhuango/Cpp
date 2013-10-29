#ifndef _EVENT_HANDLER_
#define _EVENT_HANDLER_

class Event_Handler{
	public:
//		virtual void handle_input(HANDLE handle) = 0;
//		virtual void handle_output(HANDLE handle) = 0;
//		virtual void handle_timeout(const Time_Value &) = 0;
//		virtual void handle_close(HANDLE handle, Event_Type et) = 0;
		virtual void handle_event(HANDLE handle, Event_Type et) = 0;
		//return 
		virtual HANDLE get_handle() const = 0;
};

#endif
