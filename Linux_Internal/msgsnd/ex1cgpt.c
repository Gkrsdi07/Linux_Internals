#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 1024

struct message {
    long type;
    char text[MAX_MSG_SIZE];
};

int main() {
    int msgid;
    struct message msg;

    // create a message queue
    key_t key = ftok(".", 'a');
    msgid = msgget(key, IPC_CREAT | 0666);

    if (msgid == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }

    // prepare the message
    msg.type = 1;
    strncpy(msg.text, "Hello, world!", MAX_MSG_SIZE);

    // send the message
    if (msgsnd(msgid, &msg, strlen(msg.text) + 1, 0) == -1) {
        perror("msgsnd failed");
        exit(EXIT_FAILURE);
    }

    printf("Message sent: %s\n", msg.text);

    return 0;
}

