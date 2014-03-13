#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *filename;

    if (argc != 2)
    {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(1);
    }
    filename = argv[1];

    if (!freopen(filename, "r", stdin))
    {
        fprintf(stderr, "could not redirect stdin from file %s\n", filename);
        exit(2);
    }
    
    execl("./upper", "upper", 0);

    printf("could not exec ./upper");
    exit(3);
}
