#ifndef HEAD_H
#define HEAD_h

#include "Josepher.h"

#endif

//Create a loop list
//n: the number of person
//m: the init code
PNODE CreateList(int n, int m)
{
	//c use for save code for
	//every person
	unsigned int *c;
	c = (unsigned int *)malloc(sizeof(unsigned int) * n);
	PNODE p,q;
	//Create head node
	PNODE head = (PNODE)malloc(sizeof(NODE));
	//q always point to the last node of the list
	q = head;
	//input the code;
	printf("Please input every person\'s code: \n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &c[i]);
	}
	//Create a dou-list
	for (int i = 0; i < n; ++i)
	{
		p = (PNODE)malloc(sizeof(NODE));
		//fill the data
		p->num = i + 1;
        p->code = c[i];
		q->next = p;
		p->prev = q;
		//q always point to the last one
		q = q->next;
	}
	//q point to the next of head
	//we do not use head node
	q->next = head->next;
	//head's next point to the last
	//one of the dou-list
	head->next->prev = q;
	//free head, because we do not
	//use it
	free(head);
	//q->next is the fist of the loop
	return q->next;
}


//To kill person in the loop list
//n: the number of person
//m: the init code
//list: the loop list
void KillList(int n, int m, PNODE list)
{
    //q is point to the node
    //which is ready to delete
    PNODE p = list;
    PNODE q;

    m %= n;
    while (p->next != p)
    {
        for (int i = 1; i < m-1; ++i)
        {
            p = p->next;
        }
        if (p->code == 1)
        {
            q = p;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            p = p->next;
            q->next = NULL;
            q->prev = NULL;
            free(q);
            m = p->code;
            m %= n;
        }
        else
        {
            q = p->next;
            printf("%d->", q->num);
            m = q->code;
            m %= n;
            p->next = q->next;
            q->next->prev = p;
            q->next = NULL;
            q->prev = NULL;
            free(q);
            p = p->next;
        }
    }
    printf("%d\n", p->num);
    free(p);
    return ;
}
