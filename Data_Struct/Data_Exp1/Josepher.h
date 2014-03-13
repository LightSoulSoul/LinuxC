#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>


#endif

//NODE struct define
typedef struct _NODE
{
    int code;
    int num;
    struct _NODE* next;
    struct _NODE* prev;
}NODE, *PNODE;

//Function definiontion

//Create a loop list
//n: the number of person
//m: the init code
PNODE CreateList(int n, int m);

//To kill person in the loop list
//n: the number of person
//m: the init code
//list: the loop list
void KillList(int n, int m, PNODE list);
