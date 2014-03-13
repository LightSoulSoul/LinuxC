#include "Josepher.h"
#include "Josepher.cpp"

#define DEBUG_

int main(int argc, char **argv, char ***env)
{
	#ifdef DEBUG_
	//Add test code here
	// <ToDo code here!!!>
    PNODE list = CreateList(7,20);
    for (int i = 0; i < 7; ++i)
    {
        printf("No.%d code:%d", list->num, list->code);
        list = list->next;
    }
    printf("\n");
    KillList(7,20,list);

    free(list);
    #endif


    return 0;
}
