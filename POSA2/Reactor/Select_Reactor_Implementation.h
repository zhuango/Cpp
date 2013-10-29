#ifndef _SELECT_REACTOR_IMPLEMENTATION_
#define _SELECT_REACTOR_IMPLEMENTATION_
#include "Event_Handler.h"
#include "Demux_Table.h"

class Select_Reactor_Implementation : public Reactor_Implementation{
	public:
		Select_Reactor_Implementation(){
			int index;
			for(index = 0; index < FD_SETSIZE; index ++){
				demux_table_.table_[index].event_type_ = 0;
			}
		}
		//implement of Reactor_Implementation class' virtual function
		//register handler and event on this handler
		virtual void register_handler
			(Event_Handler *event_handler,
			 Event_Type event_type);
		virtual void remove_handler
			(Event_Handler *evnet_handler,
			 Event_Type event_type);
		//implement of Reactor_Implementation class' virtual function
		//wait for events on handlers (select or poll or ...)
		virtual void handle_events();

	private:
		Demux_Table demux_table_;
};
#endif
