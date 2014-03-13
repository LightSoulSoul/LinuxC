#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

static int alarmFired = 0;

void ding(int sig)
{
    alarmFired = 1;
}

int main()
{
    pid_t pid;
    printf("alarm application statring\n");

    pid = fork();
    switch(pid)
    {
    case -1:
        /*Failure*/
        perror("fork failed!\n");
        exit(1);
    case 0:
        /*Child*/
        sleep(5);
        kill(getppid(), SIGALRM);
        exit(0);
    }

    /*if we get here we are the parent process*/
    printf("waiting for alarm to go off\n");
    (void)signal(SIGALRM, ding);

    pause();
    if (alarmFired)
        printf("Ding!\n");

    printf("done\n");
    exit(0);

}
