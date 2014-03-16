#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#include "pthread.h"
#include "semaphore.h"

void *thread_function(void *arg);
sem_t bin_sem;

#define WORK_SIZE 1024
char work_area[WORK_SIZE];

int main(int argc, char const *argv[])
{
	int res;
	pthread_t athread;
	void *thread_result;

	//init a sem_t 
	res = sem_init(&bin_sem, 0, 0);
	if (res != 0)
	{
		perror("Semaphore initialization failed.");
		exit(EXIT_FAILURE);
	}
    //Create a new thread
	res = pthread_create(&athread, NULL, thread_function, NULL);
    if (res != 0)
    {
        perror("Create thread failed!");
        exit(EXIT_FAILURE);
    }
    //input work
    printf("Input some text. Enter 'end' to finish\n");
    while (strncmp("end", work_area, 3) != 0)
    {
        fgets(work_area, WORK_SIZE, stdin);
        sem_post(&bin_sem);
    }
    //call pthred_join to wait a thread end
    printf("\nWaiting for thread to finish...\n");
    res = pthread_join(athread, &thread_result);
    if (res != 0)
    {
        perror("Thread joined failed!");
        exit(EXIT_FAILURE);
    }
    else 
    {
        printf("thread joined!");
        sem_destroy(&bin_sem);
        exit(EXIT_SUCCESS);
    }

	return 0;
}


void *thread_function(void *arg)
{
    sem_wait(&bin_sem);
    while (strncmp("end", work_area, 3) != 0)
    {
        printf("You input %d chars\n", strlen(work_area) );
        sem_wait(&bin_sem);
    }
    pthread_exit(NULL);
}




