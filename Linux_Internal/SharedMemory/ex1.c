#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
#define KEY 1234

int main(){
	int shmid;
	shmid = shmget(KEY, 8000, IPC_CREAT);
	printf("Your Shared Memory Address is: %d\n",shmid);
}
