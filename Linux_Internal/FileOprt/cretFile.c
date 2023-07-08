#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>


int main(){
	int fd;

	fd =  open("Hello.txt", O_CREAT|O_RDONLY);

	if(fd<0){
		printf("Faild to Create/Open File: %d\n",fd);
		perror("ERROR");
	}else{
		printf("File Created/Opned Successflly-FD value is: %d\n",fd);
	}
	getchar();
	return 0;
}

