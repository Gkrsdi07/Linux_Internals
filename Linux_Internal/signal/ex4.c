#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sign(){
        printf("Wakeup its 5Am time\n");
        alarm(2);
}

int main(){
	printf("PID is: %d\n",getpid());
        (void) signal(SIGALRM, SIG_IGN);
        alarm(2);
	while(1);
        return 0;
}



/*
 * GPT Code
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sign(int sig_num) {
    printf("Wakeup, it's 5 AM time\n");
    alarm(2);
}

int main() {
    // Register the signal handler
    signal(SIGALRM, sign);

    // Set the initial alarm
    alarm(2);

    while (1) {
        // Wait for a signal
        pause();
    }

    return 0;
}
*/

