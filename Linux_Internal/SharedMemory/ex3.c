#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>

#define SIZE 4096
#define KEY 1234

int main() {
    int shmid;
    char *data;
    char message[SIZE];

    shmid = shmget(KEY, SIZE, IPC_CREAT | S_IRUSR | S_IWUSR);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    data = (char *) shmat(shmid, 0, 0);
    if (data == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Enter a message: ");
    fgets(message, SIZE, stdin);
    strncpy(data, message, SIZE);

    printf("Wrote message to shared memory: %s\n", data);

    printf("Reading from shared memory: %s\n", data);

    shmdt(data);

    return 0;
}




