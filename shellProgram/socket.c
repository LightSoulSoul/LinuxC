#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "strings.h"
#include "gtk/gtk.h"

#define PORT 5678

int main()
{

	int sockfd, newsockfd, fd;
	struct sockaddr_in addr;
	int addr_len = sizeof(struct sockaddr_in);
	fd_set myreadfds;
	char msgbuffer[256];

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket");
		exit(1);
	}
	else
	{
		printf("socket created.\n");
		printf("socked id %d\n", sockfd);
	}

	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("connect");
		exit(1);
	}
	else
	{
		printf("connected.\n");
		printf("local port: %d\n", PORT);
	}

	if (listen(sockfd, 3) < 0)
	{
		perror("listen");
		exit(1);
	}
	else 
	{
		printf("listenning....\n");
	}

	if ((newsockfd = accept(sockfd, (struct sockaddr*)&addr, (socklen_t*)&addr_len)) < 0)
	{
		perror("accept");
		exit(0);
	}
	else
	{
		printf("accepted a new connection.\n");
	}

	close(sockfd);
	return 0;
}