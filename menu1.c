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
<<<<<<< HEAD
    do
    {
        choice = getchoice("Please select an action", menu);
        printf("You have chosen: %c\n", choice);
    } while(choice != 'q');
=======

    do{
        choice = getchoice("Please select an action", menu);
        printf("You have chosen: %c\n", choice);
    } whle(choice != 'q');
>>>>>>> f18a40131eee41cec7f0a4ea6f4e5eedf07ab348
    exit(0);
}

int getchoice(char *greet, char *choices[])
<<<<<<< HEAD
{
    int chosen = 0; 
    int selected;
    char **option;

    do {
        printf("Choice: %s\n", greet);
        option = choices;
        while(*option) {
            printf("%s\n", *option);
            option++;
        }
        do {
            selected = getchar();
        } while(selected == '\n');
        option = choices;
        while(*option) { 
            if (selected == *option[0]) {
                chosen = 1;
                break;
            }
            option++;
        }
        if (!chosen) {
            printf("Incorrent choice, select again\n");
        }
    } while(!chosen);

    return selected;
}
=======
>>>>>>> f18a40131eee41cec7f0a4ea6f4e5eedf07ab348


