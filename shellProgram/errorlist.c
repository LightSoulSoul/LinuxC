#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
	printf("ENOENT:\n");
	char *msg = strerror(ENOENT);
	printf("Error: %d\n", ENOENT);
	printf("Message: %s\n", msg);

	printf("EIO: \n");
	char *msg1 = strerror(EIO);
	printf("Errno: %d\n", EIO);
	printf("Message: %s\n", msg1);

	printf("EEXIST\n");
	char *msg2 = strerror(EEXIST);
	printf("Errno: %d\n", EEXIST);
	printf("Message: %s\n", msg2);

	for (int i = 0; i < 15; ++i)
	{
		printf("Errno: %d\n", i);
		printf("Message: %s\n", strerror(i));
	}

	return 0;
}