/*************************************************************************
	> File Name: fifo4.c
	> Author: Lightless
	> Mail: lightlessqxj@gmail.com 
	> Created Time: 2014年03月21日 星期五 21时24分59秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE PIPE_BUF

int main()
{
	int pipe_fd;
	int res;
	int open_mode = O_RDONLY;
	char buffer[BUFFER_SIZE + 1];
    int bytes_read = 0;

    memset(buffer, '\0', sizeof(buffer));

    printf("Process %d opening FIFO 0_RDONLY\n", getpid());
    pipe_fd = open(FIFO_NAME, open_mode);
    printf("Process %d result %d\n", getpid(), pipe_fd);

    if (pipe_fd != -1)
    {
        do
        {
            res = read(pipe_fd, buffer, BUFFER_SIZE);
            bytes_read += res;
        } while(res > 0);
        (void)close(pipe_fd);
    }
    else
    {
        exit(EXIT_FAILURE);
    }

    printf("Processed %d finished, %d bytes read\n", getpid(), bytes_read);
    exit(EXIT_SUCCESS);

}
