#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#include "pthread.h"
#include "semaphore.h"

void *thread_function(void *arg);
pthread_mutex_t work_mutex; //protects both work_area and time to exit

#define WORK_SIZE 1024
char work_area[WORK_SIZE];
int time_to_exit = 0;

int main(int argc, char const *argv[])
{
	int res;
	pthread_t athread;
	void *thread_result;

	//init a mutex 
	res = pthread_mutex_init(&work_mutex, NULL);
	if (res != 0)
	{
		perror("mutex init failed.");
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
    pthread_mutex_lock(&work_mutex);
    printf("Input some text. Enter 'end' to finish\n");
    while (!time_to_exit)
    {
        fgets(work_area, WORK_SIZE, stdin);
        pthread_mutex_unlock(&work_mutex);
        while (1)
        {
            pthread_mutex_lock(&work_mutex);
            if (work_area[0] != '\0' )
            {
                pthread_mutex_unlock(&work_mutex);
                sleep(1);
            }
            else
            {
                break;
            }
        }
    }

    pthread_mutex_unlock(&work_mutex);

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
        pthread_mutex_destroy(&work_mutex);
        exit(EXIT_SUCCESS);
    }

	return 0;
}


void *thread_function(void *arg)
{
    sleep(1);
    pthread_mutex_lock(&work_mutex);
    while  (strncmp("end", work_area, 3) != 0 )
    {
        printf("You input %d chars \n", strlen(work_area) - 1);
        work_area[0] = '\0';
        pthread_mutex_unlock(&work_mutex);
        sleep(1);
        pthread_mutex_lock(&work_mutex);
        while (work_area[0] == '\0')
        {
            pthread_mutex_unlock(&work_mutex);
            sleep(1);
            pthread_mutex_lock(&work_mutex);
        }
    }
    time_to_exit = 1;
    work_area[0] = '\0';
    pthread_mutex_unlock(&work_mutex);
    pthread_exit(0);
}


