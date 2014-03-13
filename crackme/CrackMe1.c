#include "stdio.h"
#include "stdlib.h"

int main()
{
	for (int i = 0x23B0199; i < 0xFFFFFFFF; ++i)
	{
		printf("[*]Trying 0x%X\n", i);
		int edx = i;
		edx = edx - 0xE11F79A;
		int eax = edx;
		int ecx = 0x24;
		do
		{
			eax = eax + 0x1;
			eax = (eax >> 0x2) + (eax << (32 - 0x2));
			eax = eax - 0x24B6;
			ecx = ecx - 0x1;
		}while(ecx);

		edx = 0xC4678C08;
		if (eax == edx)
		{
			printf("[!]Found! 0x%X\n", i);
			return 0;
		}
	}

	return 0;
}