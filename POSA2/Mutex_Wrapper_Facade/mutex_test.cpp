#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include "mutex_wrapper_facade.h"
Thread_Mutex Mutex;

void *print1(void *arg)
{
	Mutex.acquire();
	printf("Thread 1 get lock, sleep 1 sec......\n");
	sleep(2);
	Mutex.release();
	printf("thread 1 unlock\n");

}

void *print2(void *arg)
{
	printf("Thread start, wait for the lock\n");
	Mutex.acquire();
	printf("Thread 2 get lock, sleep 1 sec......\n");
	sleep(1);
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

	sleep(1);
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
