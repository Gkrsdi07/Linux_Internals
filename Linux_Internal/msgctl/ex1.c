#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>

#define KEY 1234

int main() {
    struct shmid_ds buf;
    int qid, q;
    int shmid;
    void *memory;

    shmid = shmget(KEY, 8000, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    printf("Your shared memory created successfully, id is: %d\n", shmid);

    memory = shmat(shmid, (const void*) 0, 0);


    q = shmctl(shmid, IPC_STAT, &buf);


    printf("Size of segment(bytes) is: %ld\n", buf.shm_segsz);
    printf("Last attach time is: %s", ctime(&buf.shm_atime));
    printf("Last detach time is: %s", ctime(&buf.shm_dtime));

    return 0;
}

