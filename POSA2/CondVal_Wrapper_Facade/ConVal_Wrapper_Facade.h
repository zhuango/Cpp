#ifndef _CONDVAL_WRAPPER_FACADE_
#define _CONDVAL_WRAPPER_FACADE_

#include<istream>
#include<pthread.h>
#include<time.h>
#include "mutex_wrapper_facade.h"

class Thread_Condition{
	public:
		Thread_Condition(Thread_Mutex &m) : mutex_ (m)
			{pthread_cond_init(&cond_, NULL); }

		~Thread_Condition(){pthread_cond_destroy(&cond_);}

		/* Wait for the signal */
		void wait(const struct timespec *timeout){
			pthread_cond_timedwait(&cond_, &mutex_.mutex_, timeout);
		}
		void wait(){
			pthread_cond_wait(&cond_, &mutex_.mutex_);
		}
		/* Send Signal to change cond*/
		void notify(){pthread_cond_signal(&cond_);}
		void notify_all(){pthread_cond_broadcast(&cond_);}
	private:
		pthread_cond_t cond_;
		Thread_Mutex &mutex_;
};

#endif
