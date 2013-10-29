#ifndef _DEMUX_TABLE_
#define _DEMUX_TABLE_

class Demux_Table{
	public:
		//Set fd bits that need to be wait for the Event
		void convert_to_fd_sets(fd_set *read_fds,
					fd_set *write_fds,
					fd_set *except_fds){
			int index;
			for(index = 0; index < FD_SETSIZE; index++){
				switch(table_[index].event_type_){
					case READ_EVENT:	FD_SET(index, read_fds);/*printf("READ : %d\n", index);*/ break;
					case WRITE_EVENT:	FD_SET(index, write_fds);/*printf("WRITE : %d\n", index);*/break;
					case SIGNAL_EVENT:	FD_SET(index, read_fds);break;
				}
			}
		}

		struct Tuple{
			//Pointer to <Event_Handler> that deal something in this handler
			Event_Handler *event_handler_;
			//Event's type
			Event_Type event_type_;
		};
		//All the handler and its Evnet_Handler is in here
		Tuple table_[FD_SETSIZE];
};

#endif
