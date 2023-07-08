#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define KEY 1234

struct msqid_ds buf;

int main(){
        int qid;
        qid = msgget(KEY,IPC_CREAT);

        msgctl(qid,IPC_STAT,&buf);  //IPC_RMID to remove
        printf("Number of msgctl in queue is: %ld\n",buf.msg_qnum);
}

