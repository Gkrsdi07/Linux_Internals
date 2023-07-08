#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	char buf[100];
	int fd;
	fd = open("Hi.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	strcpy(buf, "Hi i am Ghanshyam, I am living in SDI main Campus BBSR Odisha");
	if(fd<0){
		printf("Faild to open file, Fd value is: %d\n",fd);
		perror("ERROR");
		exit(1);
	}else{
		printf("File Opened Successfully, fs value is: %d\n",fd);
	}
	
	printf("length of buf is: %d", (int)strlen(buf));
	n = read(fd, buf, strlen(buf));
	printf("%d %d %d\n",fd,10,n); 
//	n = write(fd, buf, 10);

//	n = write(fd, buf, 11);

//	getchar();
	return 0;
}
