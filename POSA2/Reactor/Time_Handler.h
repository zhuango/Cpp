#ifndef _TIME_HANDLER_H_
#define _TIME_HANDLER_H_

class Time_Handler : public Event_Handler{
	public:
		Time_Handler(SOCK_Stream *stream, Reactor *reactor):
			peer_stream_(*stream), reactor_(reactor){
				reactor->register_handler(this, WRITE_EVENT);
		}

		virtual void handle_event(HANDLE h, Event_Type event_type){
			if(event_type == WRITE_EVENT){
				time_t ticks;
				char buff[MAXLINE];
				ticks = time(NULL);
				snprintf(buff, sizeof(buff), "<html><head>Time</head><body>%.24s</body></html>", ctime(&ticks));
				peer_stream_.Send(buff, strlen(buff), 0);
				peer_stream_.Close();
				reactor_->remove_handler(this, WRITE_EVENT);

			}else if(event_type == CLOSE_EVENT){
				peer_stream_.Close();
				delete this;
			}
		}

		virtual HANDLE get_handle() const{
			return peer_stream_.get_handle();
		}

	private:
		SOCK_Stream peer_stream_;
		Reactor *reactor_;
};

#endif
