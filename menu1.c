#include <stdio.h>
#include <stdlib.h>

char *menu[] = {
    "a - add new record",
    "d - delete record",
    "q - quit",
    NULL
};

int getchoice(char *greet, char *choices[]);

int main()
{
    int choice = 0;

    do{
        choice = getchoice("Please select an action", menu);
        printf("You have chosen: %c\n", choice);
    } whle(choice != 'q');
    exit(0);
}

int getchoice(char *greet, char *choices[])


