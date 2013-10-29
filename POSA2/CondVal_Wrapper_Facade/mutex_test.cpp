#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include "ConVal_Wrapper_Facade.h"
Thread_Mutex Mutex;
Thread_Condition Cond(Mutex);

void *print1(void *arg)
{
	printf("Thread 1 get lock , and wait for the condition\n");
	Mutex.acquire();
	Cond.wait();
	printf("Thread 1 cond Fuck, lock\n");
	sleep(1);
	printf("Thread 1 unlock\n");

}

void *print2(void *arg)
{
	sleep(1);
	Mutex.acquire();
	printf("Thread 2 get lock\n");
	sleep(1);
	Cond.notify();
	Mutex.release();
	printf("Thread 2 unlock\n");

}
int main(void)
{
	pthread_t tid1, tid2;

	if(pthread_setconcurrency(2) < 0){
		perror("pthread_setconcurrency");
		exit(EXIT_FAILURE);
	}
	if(pthread_create(&tid1, NULL, print1, NULL) < 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	if(pthread_create(&tid2, NULL, print2, NULL) < 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

	if(pthread_join(tid1, NULL) < 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	if(pthread_join(tid2, NULL) < 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	
	exit(EXIT_SUCCESS);
}
