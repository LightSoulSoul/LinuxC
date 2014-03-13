#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///////////////////////////////////////////////////////////////////
//the size of stack init
#define STACK_INIT_SIZE 32
//increment size
#define STACK_INCREMENT 16
//Buffer size
#define MAX_BUFFER 64
///////////////////////////////////////////////////////////////////
typedef struct 
{
	char* base;	//epb
	char* top; //esp
	int StackSize; //current max size
}sqStack;

typedef struct QNODE
{
	char data;
	struct QNODE* next;
}QNODE;

typedef struct 
{
	QNODE* front;	//head
	QNODE* rear;	
}LinkQueue;

///////////////////////////////////////////////////////////////////
//init stack
void InitStack(sqStack *s);
//push
void push(sqStack *s, char e);
//pop
void pop(sqStack *s, char *e);
//get stack size
int StackLen(sqStack s);

//Get stack size///////////////////////////////////////////////////////////////////
int StackLen(sqStack s)
{
	return (s.top - s.base);
}
//return 1 is empty, and return 0 is not empty
int IsStackEmpty(sqStack s)
{
	if (s.top - s.base == 0)
	{
		return 1;
	}
	return 0;
}
//pop///////////////////////////////////////////////////////////////////
void pop(sqStack* s, char* e)
{
	if (s->top == s->base)
	{
		return;
	}
	*e = *--(s->top);
}

//push////////////////////////////////////////////////////////////////////
void push(sqStack* s, char e)
{
	if (s->top - s->base >= s->StackSize)
	{
		//realloc
		s->base = (char *)realloc(s->base, (s->StackSize + STACK_INCREMENT)*sizeof(char));
		if (!s->base)
		{
			exit(0);
		}
	}
	*(s->top) = e;
	s->top++;
}

//Init///////////////////////////////////////////////////////////////////
void InitStack(sqStack *s)
{
	s->base = (char *)malloc(STACK_INIT_SIZE*sizeof(char));
	if (!s->base)
	{
		exit(0);
	}
	s->top = s->base;
	s->StackSize = STACK_INIT_SIZE;	
}

void DestroyStack(sqStack *s)
{
	free(s->base);
}
///////////////////////////////////////////////////////////////////
void InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QNODE*)malloc(sizeof(QNODE));
	if (!(Q->front))
	{
		exit(0);
	}
	Q->front->next = NULL;
}
//return 1 is empty and return 0 is not empty
int IsQueueEmpty(LinkQueue q)
{
	if (q.front - q.rear == 0)
	{
		return 1;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////
//Insert a char to rear
void EnQueue(LinkQueue* Q, char e)
{
	QNODE* p = (QNODE*)malloc(sizeof(QNODE));
	if (!p)
	{
		exit(0);
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}

//delete the front char from queue
void DeQueue(LinkQueue* Q, char* e)
{
	if (Q->rear == Q->front)
	{
		return;
	}
	QNODE* p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
	{
		Q->rear = Q->front;
	}
	free(p);
}

//Destroy the queue
void DestroyQueue(LinkQueue *Q)
{
	while(Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}

///////////////////////////////////////////////////////////////////
int main()
{
	sqStack s;
	InitStack(&s);
	LinkQueue res,t;
	//InitQueue(&q);
	InitQueue(&res);	//res save answer
	InitQueue(&t);
	char str[64] = {0};
	char astr[64] = {0};
	char bstr[64] = {0};
	printf("Please input a string:\n");
	scanf("%s", str);
	printf("Please input A->\n");
	scanf("%s", astr);
	printf("Please input B->\n");
	scanf("%s", bstr);
	//find if the ( and ) is match
	int match = 0;
	for(int i = 0 ; i < strlen(str); ++i)
	{	
		if(str[i] == '(')
			match++;
		if(str[i] == ')')
			match--;
		if(match < 0)
		{
			printf("[*]Wrong input!\n");
			exit(0);
		}	
	}
	if (match != 0)
	{
		printf("[*]Wrong input!\n");
		exit(0);
	}
	/*for (int i = 0; i < strlen(str); ++i)
	{
		if(str[i] != 't' && str[i] != 'd' && str[i] != 's' && 
			str[i] != 'a' && str[i] != 'e' && str[i] != 'z' && 
			str[i] != 'g' && str[i] != 'x' && str[i] != 'n' &&
			str[i] != 'h' && str[i] != '(' && str[i] != ')' && 
			str[i] != 'B' && str[i] != 'A')
		{	
			printf("[*]Wrong input!\n");
			exit(1);
		}
	}*/

	/*
	int left = 0, right = 0;
	for (int k = 0; k < strlen(str); ++k)
	{
		if(str[k] == '(')
			++left;
		if(str[k] == ')')
			++right;
	}
	if(left != right)
	{
		printf("[*]Do not match!\n");
		exit(0);
	}*/
	
	int i = strlen(str) - 1;
	//	printf("%d\n", i);
	//push into stack from right 2 left
	while(i>=0)
	{
		push(&s, str[i]);
		i--;
	}
	//	
	char e,key;
	char a;
	//pop the top char from the stack
	while(!IsStackEmpty(s))
	{
		pop(&s, &e);
		if (e == 'B')
		{
			//push 'tAdA' to stack
			//because 'A' need to convert
			//so, we put 'A' to stack
			//pop(&s, &e);
			/*push(&s, 'A');
			push(&s, 'd');
			push(&s, 'A');
			push(&s, 't');*/
			int len = strlen(bstr) - 1;
			while (len >= 0)
			{
				push(&s, bstr[len]);
				len --;
			}
			//or we can insert 'tsaedsae' to the queue
			//EnQueue(&q, 't');
			//EnQueue(&q, 's');
			//EnQueue(&q, 'a');
			//EnQueue(&q, 'e');
			//EnQueue(&q, 'd');
			//EnQueue(&q, 's');
			//EnQueue(&q, 'a');
			//EnQueue(&q, 'e');

		}
		else if (e == 'A')
		{
			//insert "sae" to the queue
			/*EnQueue(&res, 's');
			EnQueue(&res, 'a');
			EnQueue(&res, 'e');*/
			int len = 0;;
			while (len <= strlen(astr) - 1)
			{
				EnQueue(&res, astr[len]);
				len++;
			}
		}
		else if (e == '(')
		{
			pop(&s, &key);
			pop(&s, &e);
			do
			{
				EnQueue(&t, e);
				pop(&s, &e);
			}while(e != ')');
			while(!IsQueueEmpty(t))
			{
				push(&s, key);
				DeQueue(&t, &a);
				push(&s, a);
			}
			push(&s, key);

		}
		else	//normol char directly to insert to the queue 
		{
			EnQueue(&res, e);
		}
	}
	//wchar_t ans[128] = {0};
	//i = 0;
	//show the answer
	/*while(!IsQueueEmpty(res))
	{
		DeQueue(&res, &e);
		switch(e)
		{
		case 't':
			printf("天");
			break;
		case 'd':
			printf("地");
			break;
		case 's':
			printf("上");
			break;
		case 'a':
			printf("一只");
			break;
		case 'e':
			printf("鹅");
			break;
		case 'z':
			printf("追");
			break;
		case 'g':
			printf("赶");
			break;
		case 'x':
			printf("下");
			break;
		case 'n':
			printf("蛋");
			break;
		case 'h':
			printf("恨");
			break;
		}
		
		//printf("%c", e);
	}*/
	while(!IsQueueEmpty(res))
	{
		DeQueue(&res, &e);
		printf("%c", e);
	}
	putchar('\n');
	DestroyQueue(&t);
	DestroyQueue(&res);
	//DestroyQueue(&q);
	DestroyStack(&s);
	return 0;
}
