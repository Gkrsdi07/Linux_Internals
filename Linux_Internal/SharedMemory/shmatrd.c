#include <sys/types.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define KEY 1234

int main() {
    int shmid;
    void *memory;
    char buffer[8000];

    shmid = shmget(KEY, 8000, IPC_CREAT | 0666);
    printf("Your shared memory created successfully, id is: %d\n", shmid);

    memory = shmat(shmid, NULL, 0);

    printf("Data read from shared memory: %s\n", (char*) memory);

}

