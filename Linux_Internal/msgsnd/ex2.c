#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
               long mtype;       /* message type, must be > 0 */
               char mtext[1];    /* message data */
           };


int main(){
	int qid;
	int i;
	msg m1,m2,m3;
	qid = msgget(KEY,IPC_CREAT);
	printf("%d",qid);

}
~   

