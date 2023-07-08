#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	printf("Hello Fork \n");
	printf("My Process pid is : %d\n",getpid());
	printf("My Process ppid is : %d\n",getppid());
	fork();
	printf("Hi Fork \n");
	getchar();
}
