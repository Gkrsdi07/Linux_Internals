#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t myConVar = PTHREAD_COND_INITIALIZER;

int doneFlag = 0;
char buf[100];

/* Producer thread*/
void * threadA(void *p){
	printf("\nthreadA Scheduled first\n");
	sleep(1);
	pthread_mutex_lock(&my_mutex);
	printf("\nthreadA: critical section executes always first\n");

	/* Producer will produce data here*/
	sprintf(buf, "This is data Buffer");
	doneFlag = 1;
	pthread_cond_signal(&myConVar);
	pthread_mutex_unlock(&my_mutex);
}

/* Consumer thread*/
void * threadB(void *p){
	printf("\nthreadB Scheduled first\n");
        
        pthread_mutex_lock(&my_mutex);

	if(doneFlag == 0)
		pthread_cond_wait(&myConVar, &my_mutex);	

        /* Consumer will produce data here*/
	printf("\nthreadB: signal received from threadA, this is alwaya executed after threadA critical section %d\n",doneFlag);
	printf("\nThe buffer received from producer thread is (%s)\n",buf);

        pthread_mutex_unlock(&my_mutex);
}


int main(int argc, char** argv){
	srand(time(0));
	pthread_t pthreadA;
	pthread_create(&pthreadA, NULL, threadA, NULL);
	pthread_t pthreadB;
        pthread_create(&pthreadB, NULL, threadB, NULL);
	pthread_join(pthreadA,NULL);
	pthread_join(pthreadB,NULL);
	printf("\nMain thread is exiting now\n");
	return (EXIT_SUCCESS);
}
