#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <stdlib.h>

int main()
{
    initscr();

    move(5, 15);

    printf("%s", "Hello world!\n");
    refresh();

    sleep(2);
    endwin();
    exit(EXIT_SUCCESS);
}
