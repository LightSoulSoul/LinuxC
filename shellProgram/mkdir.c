#include "stdio.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "errno.h"
#include "string.h"
#include "fcntl.h"
#include "stdlib.h"

#define PERMISSION 0766

int main()
{
	char path[] = "/home/lightless/Program/shellProgram/a.c";
	int fd, fd1;
	extern int errno;
	fd = open(path, O_WRONLY, 0766);
	f



	return 0;
}
