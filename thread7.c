#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

int main()
{
    int res;
    pthread_t athread;
    void *thread_result;

    //try to create a thread
    res = pthread_create(&athread, NULL, thread_function, NULL);
    if (res != 0 /*res*/)
    {
        perror("Thread create failed!\n");
        exit(EXIT_FAILURE);
    }

    //try to cancel a thread
    // try to fix this number to others number 
    sleep(6);
    printf("Canceling thread...\n");
    res = pthread_cancel(athread);
    if (res != 0 /*res*/)
    {
        perror("Thread cancel failed.");
        exit(EXIT_FAILURE);
    }

    //wait for a thread
    printf("Waiting for thread to finish...\n");
    res = pthread_join(athread, &thread_result);
    if (res != 0)
    {
        perror("Thread join failed.");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
    int i, res;
    
    //try to set cancel state
    res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    if (res != 0 /*res*/ )
    {
        perror("Thread setcancelstate failed.\n");
        exit(EXIT_FAILURE);
    }
    
    //try to set cancel type
    res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    if (res != 0)
    {
        perror("Thread set cancel type failed.\n");
        exit(EXIT_FAILURE);
    }

    //POC of thread is running...
    printf("thread_function is running\n");
    for (i = 0; i < 10; i++)
    {
        printf("Thread is still running %d..\n", i);
        sleep(1);
    }
    pthread_exit(0);
}


