#include <stdio.h>
#include <stdlib.h>
#include "handle.h"
#include "Event_Type.h"
#include "Event_Handler.h"
#include "Demux_Table.h"
#include "Reactor_Implementation.h"
#include "Select_Reactor_Implementation.h"
#include "Reactor.h"

void Select_Reactor_Implementation::register_handler
	(Event_Handler *event_handler,
	 Event_Type event_type)
{
	//New a Event_Handler object
	demux_table_.table_[event_handler->get_handle()].event_handler_ = event_handler;
	//Set type of event
	demux_table_.table_[event_handler->get_handle()].event_type_ = event_type;
}

void Select_Reactor_Implementation::remove_handler
	(Event_Handler *event_handler,
	 Event_Type event_type)
{
	//clear the event table
	demux_table_.table_[event_handler->get_handle()].event_handler_ = NULL;
	demux_table_.table_[event_handler->get_handle()].event_type_ = 0;
}

void Select_Reactor_Implementation::handle_events()
{
	//Select function should listen
	fd_set read_fds, write_fds, except_fds;
	//Clear fds
	FD_ZERO(&read_fds);
	FD_ZERO(&write_fds);
	FD_ZERO(&except_fds);
	//Get fd need to listen
	demux_table_.convert_to_fd_sets(&read_fds, &write_fds, &except_fds);
	//Set the max fd number
	HANDLE max_handle = FD_SETSIZE;

	//Select
	int result = select(max_handle + 1, &read_fds, &write_fds, &except_fds, NULL);
	//Error ?
	if(result <= 0){
		perror("select");
		exit(EXIT_FAILURE);
	}
	//Go through the fd_set and deal with event
	for(HANDLE h = 0; h <= FD_SETSIZE; h++){
		if(FD_ISSET(h, &read_fds)){//Read event
			demux_table_.table_[h].event_handler_->handle_event(h, READ_EVENT);
		}
		if(FD_ISSET(h, &write_fds)){//Write event
			demux_table_.table_[h].event_handler_->handle_event(h, WRITE_EVENT);
		}
	}
}

