#include <stdio.h>
#include <stdlib.h>

int main()
{
	//a:unit
	//b:decade
	//c:hundreds
	int a = 0, b = 0 , c = 0;
	for (int i = 100; i < 1000; ++i)
	{
		a = i % 100 % 10;
		b = i / 10 % 10;
		c = i / 100;

		if (a*a*a+b*b*b+c*c*c==i)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}




