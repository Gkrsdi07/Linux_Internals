#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sign(int sig){
	printf("My - I got my 1st signal %d\n", sig);
	(void) signal(SIGINT, SIG_DFL);
}

int main(){
	(void) signal(SIGINT, sign);
	while(1){
		printf("Hello World\n");
		sleep(1);
	}
	return 0;
}

