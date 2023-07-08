#include<stdio.h>
#include <unistd.h>

int main(){
	int pid;
	printf("Before fork ppid is: %d\n",getpid());
	
	pid = fork();
	printf("%d pid \n",pid);

	//if ((pid >  0))
          // printf("hello from the parent\n",getppid());
       //else
         //  printf("hello from the child\n",getpid());

	//getchar();
}
