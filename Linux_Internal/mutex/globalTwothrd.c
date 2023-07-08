#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


static int global = 0;

static void *threadFunc1(void *arg){
	int loc, j;
	int loop = 1000;
	for(j=0;j<loop;j++){
		loc = global;
		loc++;
		global = loc;
	}
	printf("ThreadFunc1 Loop %d\n",loc);
	return NULL;
}


static void *threadFunc2(void *arg){
        int loc, j;
        int loop = 1000;
        for(j=0;j<loop;j++){
                loc = global;
                loc++;
                global = loc;
        }
	printf("ThreadFunc2 Loop %d\n",loc);
        return NULL;
}



int main(int argc, char *argv[]){
	pthread_t tid1, tid2;
	int s;
	
	if(s != 0)
               perror("pthread_created");
	s = pthread_create(&tid1, NULL, threadFunc1, NULL);

	if(s != 0)
		perror("pthread_created");
	s = pthread_create(&tid2, NULL, threadFunc2, NULL);

	if(s != 0){
		perror("pthread_create");
	}	
	s = pthread_join(tid1, NULL);

	if(s !=0)
		perror("pthread_join");
	s = pthread_join(tid2, NULL);

	if(s != 0)
		perror("pthread_join");
	printf("global = %d\n",global);
	exit(0);
}
