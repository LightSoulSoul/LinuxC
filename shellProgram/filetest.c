#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	FILE *fp;
	extern int errno;
	char file[] = "/root/a1.txt";
	char txt[6] = "hello";
	int i = 0;
	fp = fopen(file, "a+");

	if (fp == NULL)
	{
		printf("can't open %s.\n", file);
		printf("errno: %d\n", errno);
		printf("ERR: %s\n", strerror(errno));
	}
	else
	{
		printf("%s was opened.\n", file);
	}

	for (int i = 0; i < 5; ++i)
	{
		putc(txt[i], fp);
		printf("%c", txt[i]);
	}
	fclose(fp);

}
