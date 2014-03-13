#include "sys/types.h"
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[])
{
	pid_t pid;
	char *message;
	int n;
    int exit_code;
    
	printf("fork program starting\n");
	pid = fork();

	switch(pid)
	{
		case -1:
			perror("fork failed\n");
			break;
		case 0:
			message = "This is the child";
			n = 5;
            exit_code = 37;
			break;
		default:
			message = "This is the parent";
			n = 3;
            exit_code = 0;
			break;
	}
	for (; n > 0; n--)
	{
		puts(message);
		sleep(1);
	}

    if (pid != 0)
    {
        int stat_val;
        pid_t childpid;

        childpid = wait(&stat_val);

        printf("Child has finished: PID = %d\n", childpid);
        if (WIFEXITED(stat_val))
            printf("Child exited with code %d\n", WIFEXITED(stat_val));
        else
            printf("Childe terminated abnormally \n");
    }
    exit(exit_code);

	return 0;
}
