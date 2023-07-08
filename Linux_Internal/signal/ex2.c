#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sign(int sig){
        printf("My - I got my 1st signal %d\n", sig);
        //(void) signal(SIGINT, SIG_DFL);
}

int main(){
	printf("My Process id is: %d\n",getpid());
        (void) signal(SIGTERM, SIG_IGN);
        while(1){
                printf("Hello World\n");
                sleep(1);
        }
        return 0;
}

