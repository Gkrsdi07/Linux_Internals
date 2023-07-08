#include<stdio.h>
#include <unistd.h>
int main(){
	char *file = "/s";
	char *args1 = "-a";
	char *args2 = "-s";
        char *args[] = {"./execlp",NULL};
        printf("Hello I am Ghanshyam, my id is: %d\n",getpid());
        execlp(args[0],args1,args2);
        printf("I am Ghanshyam Kumar\n");
        return 0;
}

