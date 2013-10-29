#ifndef _MUTEX_WRAPPER_FACADE_
#define _MUTEX_WRAPPER_FACADE_

#include<iostream>
#include<pthread.h>

class Thread_Mutex{
	public:
		Thread_Mutex()
			{pthread_mutex_init(&mutex_, NULL);}/* Init mutex */
		~Thread_Mutex(){pthread_mutex_destroy(&mutex_);}/* Destroy mutex */

		void acquire(){pthread_mutex_lock(&mutex_);}/* Lock */
		void release(){pthread_mutex_unlock(&mutex_);}/* Unlock */

	private:
		pthread_mutex_t mutex_;/* Mutex value */
		
		Thread_Mutex(const Thread_Mutex &);/* Can not copy */
		void operator= (const Thread_Mutex &);/* Can not = */

		//friend class Thread_condition;
};

#endif
