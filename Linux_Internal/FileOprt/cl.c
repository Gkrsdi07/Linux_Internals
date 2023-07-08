#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd<0){
		printf("Faild to create socket: %d\n",sockfd);
		perror("ERROR");
	}else{
		printf("Sockect Created Successfully : %d\n",sockfd);
	}
	getchar();
}

