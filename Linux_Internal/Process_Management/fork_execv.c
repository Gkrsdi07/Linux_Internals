#include<stdio.h>
#include <unistd.h>

int main(){
	pid_t frk_val;

	frk_val = fork();

	if(frk_val < 0){
		printf("Fail to Create Child\n");
	}else if(frk_val == 0){
		printf("I am in Child Process, id is: %d\n",getpid());
		char *args[] = {"./execv",NULL};
		execv(args[0],args);
	}else{
		printf("I am from Parent id is: %d\n",getpid());
	}
}
