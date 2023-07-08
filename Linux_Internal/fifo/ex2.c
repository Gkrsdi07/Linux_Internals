#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
        char ch[20];
        char ch1[20];
        mkfifo("file1",0666);
        mkfifo("file2",0666);
        int fd = open("file1",O_RDONLY);
        int fd1 = open("file2",O_WRONLY);

        while(1){
		read(fd,ch1,sizeof(ch1));
		printf("Received Message: %s\n",ch1);
		sleep(1);
                printf("Enter the Message to send...\n");
                scanf("%s",ch);
                write(fd1,ch,strlen(ch)+1);
        }
}

