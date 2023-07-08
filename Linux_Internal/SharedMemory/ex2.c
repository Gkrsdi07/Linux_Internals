#include <sys/types.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define KEY 1234

int main() {
    int shmid;
    void *memory;

    shmid = shmget(KEY, 8000, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    printf("Your shared memory created successfully, id is: %d\n", shmid);

    memory = shmat(shmid, NULL, 0);
    if (memory == (void *) -1) {
        perror("shmat");
        return 1;
    }

    strcpy((char *) memory, "Ghanshyam");

    printf("Your shared memory address is: %p\n", (int *) memory);

    return 0;
}

