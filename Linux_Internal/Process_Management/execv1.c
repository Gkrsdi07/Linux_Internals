#include<stdio.h>
#include <unistd.h>
int main(){
	char *args[] = {"./execv",NULL};
	printf("Hello I am Ghanshyam, my id is: %d\n",getpid());
	execv(args[0],args);
	printf("I am Ghanshyam Kumar\n");
	return 0;
}
