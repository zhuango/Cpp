#include <stdio.h>
#include <stdlib.h>
#include "handle.h"
#include "Event_Type.h"
#include "Event_Handler.h"
#include "Demux_Table.h"
#include "Reactor_Implementation.h"
#include "Select_Reactor_Implementation.h"
#include "Reactor.h"

//register handler and event on this handler
void Reactor::register_handler (Event_Handler *eh, Event_Type et)
{
	reactor_impl_->register_handler(eh, et);
}

void Reactor::remove_handler(Event_Handler *eh, Event_Type et)
{
	reactor_impl_->remove_handler(eh, et);
}

void Reactor::handle_events (){
	reactor_impl_->handle_events();
}

Reactor *Reactor::reactor_ = NULL;

//Singleton
Reactor *Reactor::instance()
{
	if(reactor_ == NULL){
		reactor_ = new Reactor();
	}
	
	return reactor_;
}
