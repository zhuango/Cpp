#ifndef _REACTOR_H_
#define _REACTOR_H_
typedef int HANDLE;
//class Reactor_Implementation;
class Reactor{
	public:
		virtual void register_handler
			(Event_Handler *eh, Event_Type et);

//		virtual void register_handler
//			(HANDLE h, Event_Handler *eh, Event_Type et) = 0;

		virtual void remove_handler
			(Event_Handler *eh, Event_Type et);

//		virtual void remove_handler
//			(HANDLE h, Event_Type et) = 0;

		
		//void handle_events(Time_Value *timeout = 0);
		virtual void handle_events();

		static Reactor *instance();

	protected:
		Reactor(){
			reactor_impl_ = new Select_Reactor_Implementation();
		}

	private:
		static Reactor *reactor_;
		Reactor_Implementation *reactor_impl_;
};

#endif
