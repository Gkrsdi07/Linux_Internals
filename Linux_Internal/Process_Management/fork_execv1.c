#include<stdio.h>
#include <unistd.h>

int val;

int main(){
	int childState;

        pid_t frk_val;

        frk_val = fork();

        if(frk_val < 0){
                printf("Fail to Create Child\n");
        }else if(frk_val == 0){
                printf("I am in Child Process, id is: %d\n",getpid());
                //char *args[] = {"./execv",NULL};
                //execv(args[0],args);
		val = 10;
		printf("From Child value is: %d\n",val);
		sleep(20);
		//wait(&childState);
        }else{
		wait();
                //printf("I am from Parent id is: %d\n",getpid());
		val = 20;
		printf("From Parent value is: %d\n",val);
		sleep(25);

        }

}

