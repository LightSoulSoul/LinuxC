#include <stdio.h>

char ss[] = "D_kbwqj_fs";

int main()
{
	int i = 0;
	for (i = 1; i < 10; i+=2)
		ss[i] = ss[i] + 2;

	for (i = 0; i < 10; i+=2)
		ss[i] = ss[i] - 2;

	for (i = 0; i < 10; ++i)
	{
		printf("%c", ss[i]);
	}
	return 0;
}