#include <stdio.h>
#include <stdlib.h>
#include <string.h>
////////////////////////////////////////////////////////////
///Typedef sth.
//typedef a new node for input
typedef struct _NEWNODE
{
	unsigned char symbol;
	unsigned int frequence;
}NEWNODE;

//Typedef huffman tree node.
typedef struct _HTNODE
{
	char symbol;
	struct _HTNODE *lchild, *rchild;
}HTNODE, *PHTNODE;

//Typedef huffman Tree Head.
//root point to the root node of the huffman tree
typedef struct _HTTREE
{
	PHTNODE root;
}HTTREE;

//The huffman table nodes
typedef struct _HLNODE
{
	char symbol;
	char *code;
	struct _HLNODE *next;
}HLNODE, *PHLNODE;

//Huffman table list
typedef struct _HLTABLE
{
	PHLNODE first;
	PHLNODE last;
}HLTABLE;

//typedef Queue node
typedef struct _QUEUENODE
{
	PHTNODE val;	//for tree node
	unsigned int priority;
	struct _QUEUENODE *next;
}QUEUENODE, *PQUEUENODE;

//typedef Queue 
typedef struct _QUEUE
{
	unsigned int size;
	PQUEUENODE first;
}QUEUE;

////////////////////////////////////////////////////////////////////
void initQueue(QUEUE **queue);
void addQueue(QUEUE **queue, PHTNODE val, unsigned int priority);
PHTNODE getQueue(QUEUE **queue);
HTTREE * buildTree(char *inputString, NEWNODE* input, int number);
HLTABLE * buildTable(HTTREE *huffmanTree);
void encode(HLTABLE *table, char *stringToEncode);
void decode(HTTREE *tree, char *stringToDecode);

//initQueue
void initQueue(QUEUE **queue)
{
	(*queue) = (QUEUE* )malloc(sizeof(QUEUE));
	(*queue)->first = NULL;
	(*queue)->size = 0;
	return ;
}


//build huffman tree
HTTREE * buildTree(char *inputString, NEWNODE* input, int number)
{
	
	//probability save ascii  and empty the array
	int * probability = (int *)malloc(sizeof(int ) * 256);
	for (int i = 0; i < 256; ++i)
	{
		probability[i] = 0;
	}
	
	//calculate the every char's appears.
/*	for (int i = 0; inputString[i] != '\0'; ++i)
	{
		probability[ (unsigned char)inputString[i] ]++;
	}*/
	for (int i = 0; i < number; ++i)
	{
		probability[ (unsigned int)input[i].symbol ] = input[i].frequence;
	}
/*	probability[65] = 64;
	probability[66] = 13;
	probability[67] = 22;	//c
	probability[68] = 32;	//d
	probability[69] = 103;	//e
	probability[70] = 21;	//f
	probability[71] = 15;	//g
	probability[72] = 47; 	//h
	probability[73] = 57;	//i
	probability[74] = 1; 	//j
	probability[75] = 5;	//k
	probability[76] = 32;	//l
	probability[77] = 20;	//m
	probability[78] = 57;	//n
	probability[79] = 63;	//o
	probability[80] = 15;	//p
	probability[81] = 1;	//q
	probability[82] = 48;	//r
	probability[83] = 51;	//s
	probability[84] = 80;	//t
	probability[85] = 23;	//u
	probability[86] = 8;	//v
	probability[87] = 18;	//w
	probability[88] = 1;	//x
	probability[89] = 16;	//y
	probability[90] = 1;	//z
	probability[32] = 186;	//space*/
	
	//init a queue, and save tree node
	QUEUE *huffmanQueue;
	initQueue(&huffmanQueue);

	//create nodes for each char in the input string
	for (int i = 0; i < 256; ++i)
	{
		if (probability[i] != 0)
		{
			PHTNODE aux = (PHTNODE)malloc(sizeof(HTNODE));
			aux->lchild = NULL;
			aux->rchild = NULL;
			aux->symbol = (char)i;

			addQueue(&huffmanQueue, aux, probability[i]);
		}
	}
	//free the array
	free(probability);
	//build the tree
	while(huffmanQueue->size != 1)
	{
		int priority = huffmanQueue->first->priority;
		priority += huffmanQueue->first->next->priority;

		PHTNODE left = getQueue(&huffmanQueue);
		PHTNODE right = getQueue(&huffmanQueue);

		PHTNODE newNode = (PHTNODE)malloc(sizeof(HTNODE));
		newNode->lchild = left;
		newNode->rchild = right;

		addQueue(&huffmanQueue, newNode, priority);
	}
	//Create the tree
	//stop here, there is only one node in the queue
	HTTREE *tree = (HTTREE *)malloc(sizeof(HTTREE));
	tree->root = getQueue(&huffmanQueue);
	return tree;

}

//addQueue
void addQueue(QUEUE **queue, PHTNODE val, unsigned int priority)
{
	//if the queue is full...quit
	if ((*queue)->size == 256)
	{
		printf("[!]ERROR: Queue has been fulled!");
		return;
	}
	//create a queue node to save the new node ... 
	//ready add it to the queue
	PQUEUENODE aux = (PQUEUENODE)malloc(sizeof(QUEUENODE));
	aux->priority = priority;
	aux->val = val;

	//if the queue is empty, add the node to the first
	if ((*queue)->size == 0 || (*queue)->first == NULL)
	{
		aux->next = NULL;
		(*queue)->first = aux;
		(*queue)->size = 1;
		return ;
	}
	//insert the node....which added is greater than the priority of the first element
	//and add it in front of the first element
	//and make an order queue!!!!!
	else 
	{
		if (priority <= (*queue)->first->priority)
		{
			aux->next = (*queue)->first;
			(*queue)->first = aux;
			(*queue)->size ++;
			return;
		}
		else	//find a suitable palce to insert the node
		{
			PQUEUENODE iterator = (*queue)->first;
			while(iterator->next != NULL)
			{
				if (priority <= iterator->next->priority)
				{
					aux->next = iterator->next;
					iterator->next = aux;
					(*queue)->size ++;
					return;	
				}
				iterator = iterator->next;
			}
			//if there is no fit palce ,
			//add it to the end of the queue
			if (iterator->next == NULL)
			{
				aux->next = NULL;
				iterator->next = aux;
				(*queue)->size++;
				return;
			}
		}
	}

	return ;
}

//Get Queue
PHTNODE getQueue(QUEUE **queue)
{
	PHTNODE returnValue;
	//Get the node from the queue
	if ((*queue)->size > 0)
	{
		returnValue = (*queue)->first->val;
		(*queue)->first = (*queue)->first->next;
		(*queue)->size --;
	}
	//if the queue is empty ...
	else
	{
		printf("[!]ERROR: Queue is empty!");
		return NULL;
	}
	return returnValue;
}

//travesal Tree
void TraverseTree(PHTNODE treeNode, HLTABLE **table, int level, char code[256])
{
	//if this is the leaves 
	//fill the code
	if (treeNode->lchild == NULL && treeNode->rchild == NULL)
	{
		code[level] = '\0';
		PHLNODE aux = (PHLNODE)malloc(sizeof(HLNODE));
		aux->code = (char *)malloc(sizeof(char)*(strlen(code) + 1));
		strcpy(aux->code, code);
		aux->symbol = treeNode->symbol;
		aux->next = NULL;
		if ((*table)->first == NULL)
		{
			(*table)->first = aux;
			(*table)->last = aux;
		}
		else
		{
			(*table)->last->next = aux;
			(*table)->last = aux;
		}
	}
	//left and right
	if (treeNode->lchild != NULL)
	{
		code[level] = '0';
		TraverseTree(treeNode->lchild, table, level+1, code);
	}
	if (treeNode->rchild != NULL)
	{
		code[level] = '1';
		TraverseTree(treeNode->rchild, table, level+1, code);
	}
}

//build table
HLTABLE *buildTable(HTTREE * huffmanTree)
{
	//init the table
	HLTABLE *table = (HLTABLE *)malloc(sizeof(HLTABLE));
	table->first = NULL;
	table->last = NULL;
	char code[256];
	for (int i = 0; i < 256; ++i)
	{
		code[i] = 0;
	}
	//level_var show the level of traversal 
	int level = 0;
	//TraverseTree and create the table
	TraverseTree(huffmanTree->root, &table, level, code);
	return table;
}

//encode
void encode(HLTABLE *table, char *stringToEncode)
{
	PHLNODE traversal;
	FILE * CodeFile = fopen("CodeFile", "w");
	if(!CodeFile)
	{
		printf("[!]ERROR: Open file failed!");
		exit(0);
	}
	printf("[*]Try to encode %s...\n", stringToEncode);
	printf("[*]Result: ");
	for (int i = 0; stringToEncode[i] != '\0'; ++i)	
	{
		traversal = table->first;	
		while(traversal->symbol != stringToEncode[i])
		{
			traversal = traversal->next;
		}
		printf("%s", traversal->code);
		fprintf(CodeFile, "%s", traversal->code);
	}
	fclose(CodeFile);
}
//Decode
void decode(HTTREE *tree, char *stringToDecode)
{
	PHTNODE traversal = tree->root;
	FILE *TextFile = fopen("TextFile", "w+");
	if(!TextFile)
	{
		printf("[!]ERROR: Open file failed!\n");
	}
	printf("[*]Try to decode %s...\n", stringToDecode);
	printf("[*]Resutl: ");
	for (int i = 0; stringToDecode[i] != '\0'; ++i)
	{
		if (traversal->lchild == NULL && traversal->rchild == NULL)
		{
			printf("%c",  traversal->symbol);
			fprintf(TextFile, "%c", traversal->symbol);
			traversal = tree->root;
		}
		if (stringToDecode[i] == '0')
		{
			traversal = traversal->lchild;
		}
		if (stringToDecode[i] == '1')
		{
			traversal = traversal->rchild;
		}
		if (stringToDecode[i] != '0' && stringToDecode[i] != '1')
		{
			printf("[!]ERROR: The input string is wrong!");
			return;
		}
	}
	if (traversal->lchild == NULL && traversal->rchild == NULL)
	{
		printf("%c", traversal->symbol);
		fprintf(TextFile, "%c", traversal->symbol);
		traversal  = tree->root;
	}
	printf("\n[*]Decode Done.\n[*]Write to file \"TextFile\"");
	printf("\n");
	fclose(TextFile);
	return ;
}

void PrintTable(HTNODE *tree, int level)
{
	int currentLevel = level;
	PHTNODE traversal = tree;
	if(traversal->lchild == NULL && traversal->lchild == NULL)
	{	
		while(currentLevel--)
		{
			printf("+");
		}
		printf("%c\n", traversal->symbol);
	}
	currentLevel = level;
	if(traversal->lchild != NULL)
	{
		//while(currentLevel--)
		//{
		//	printf("+");
		//}
		//printf("%c", traversal->symbol);
		PrintTable(traversal->lchild, level+1);
	}
	currentLevel = level;
	if(traversal->rchild != NULL)
	{
		//while(currentLevel--)
		//{
			//printf("+");
		//}
		//printf("%c", traversal->symbol);
		PrintTable(traversal->rchild, level+1);
	}
	
}

int main()
{
/*	//1.Build the tree depending on the string
	HTTREE *codeTree = buildTree("THIS PROGRAM");
	//2.build the table depending on the huffman tree
	HLTABLE *codeTable = buildTable(codeTree);
	//3.encode the string
	encode(codeTable, "THIS PROGRAM IS MY FAVORITE");
	//4.decode the string
	decode(codeTree, "1101000101110011111100001001010011000100010101111001011101110011111110010100011111110011101111000001001001001111101010");
*/

	int level = 0;
	int number = 0;
	NEWNODE *input;
	char c;
	HTTREE *codeTree;
	HLTABLE *codeTable;
	FILE *hfmTree;
	PHLNODE write2file;
	FILE *CodeFile;
	char fc;
	char buffer[512];
	int iw;
	FILE *ToBeTran;
	FILE *CodePrint;
	//HTTREE *tree;
	while(1)
	{
		char selector = 0;
		printf("1.Initialization please input \'I\' and press enter.\n");
		printf("2.Encode the string please input \'E\' and press enter\n");
		printf("3.Decode the string please input \'D\' and press enter\n");
		printf("4.Print the string please input \'P\' and press enter\n");
		printf("5.Print the tree please input \'T\' and press enter\n");
		printf("Please input an char(\'Q\' for quit): ");
		scanf("%c", &selector);
		//c = getchar();
		switch(selector)
		{
		case 'I':
			printf("Please input how many chars you need.");
			//input the node data
			scanf("%d", &number);
			input = (NEWNODE* )malloc(sizeof(NEWNODE)*number);
			for (int i = 0; i < number; ++i)
			{
				printf("Please input the %d char: ", i+1);
				c = getchar();
				scanf("%c", &input[i].symbol);
				printf("Please input the %d frequence: ", i+1);
				scanf("%d", &input[i].frequence);
				//c = getchar();
			}
			printf("[*]Building Huffman Tree...\n");
			//codeTree = (HTTREE *)malloc(sizeof(HTTREE));
			codeTree = buildTree("THIS PROGRAM", input, number);
			codeTable = buildTable(codeTree);
			//write to file
			hfmTree = fopen("hfmTree", "w");
			if (!hfmTree)
			{
				printf("[!]ERROR: Open file failed!\n");
				return 0;
			}
			write2file = (PHLNODE)malloc(sizeof(HLNODE));
			write2file = codeTable->first;
			while(write2file != NULL)
			{
				fprintf(hfmTree, "%c --> %s\n", write2file->symbol, write2file->code);
				write2file = write2file->next;
			}
			fclose(hfmTree);
			printf("[*]Build Done.\n[*]Write to file \"hfmTree\"\n");
			break;
		case 'E':
			printf("[*]Encoding...\n");
			ToBeTran = fopen("ToBeTran", "r");
			if (!ToBeTran)
			{
				printf("[*]ERROR: Open file failed!\n");
			}			

			iw = 0;
			for (int i = 0; i < 512; ++i)
			{
				buffer[i] = 0;
			}
			while((fc = fgetc(ToBeTran)) != EOF)
			{
				buffer[iw] = fc;
				iw++;
			}
			iw++; buffer[iw] = '\0';
			//printf("Before encode: %s", buffer);
			encode(codeTable, buffer);
			//CodeFile = fopen("CodeFile", "w");

			fclose(ToBeTran);
			printf("\n[*]Encode done.\n");
			printf("[*]Write to file \"CodeFile\"\n");
			break;
		case 'D':
			CodeFile = fopen("CodeFile", "r");
			for(int i = 0; i < 512; ++i)
			{
				buffer[i] = 0;
			}
			fscanf(CodeFile, "%s", buffer);
			decode(codeTree, buffer);
			break;
		case 'P':
			CodePrint = fopen("CodePrint", "w");
			if(!CodePrint)
			{
				printf("[!]ERROR: Open file failed!");
			}
			CodeFile = fopen("CodeFile", "r");
			if(!CodeFile)
			{
				printf("[!]ERROR: Open file failed!");
			}
			printf("[*]Print Code...\n");;
			for(int i = 0; i < 512; ++i)
			{
				buffer[i] = 0;
			}
			fscanf(CodeFile, "%s", buffer);
			for(int i = 0; buffer[i] != '\0'; ++i)
			{
				printf("%c", buffer[i]);
				fprintf(CodePrint, "%c", buffer[i]);
				if(i%50 == 0 && i != 0)
				{
					printf("\n");
					fprintf(CodePrint, "\n", buffer[i]);
				}
			}
			fclose(CodePrint);
			fclose(CodeFile);
			printf("\n[*]Print Done.\n");
			break;
		case 'T':
			//Current is 1 level
			level = 1;
			printf("[*]Print Table...\n");
			PrintTable(codeTree->root, level);
			printf("[*]Done..\n");
			break;
		case 'Q':
			printf("[*]Bye.\n");
			exit(0);
		default:
			printf("[!]Wrong input!\n");
			break;
		}
	}


	return 0;
}