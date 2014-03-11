#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

const char *testFile = "/tmp/test_lock";
#define SIZE_TO_TRY (5)

void ShowLockInfo(struct flock *toShow);

int main()
{
    int file_desc;
    int res;
    struct flock regionToTest;
    int startByte;

    file_desc = open(testFile, O_RDWR|O_CREAT, 0666);
    if (!file_desc)
    {
        fprintf(stderr, "Unable to open %s for read/write\n", testFile);
        exit(EXIT_FAILURE);
    }

    for (startByte = 0; startByte < 99; startByte += SIZE_TO_TRY)
    {
        regionToTest.l_type = F_WRLCK;
        regionToTest.l_whence = SEEK_SET;
        regionToTest.l_start = startByte;
        regionToTest.l_len = SIZE_TO_TRY;
        regionToTest.l_pid = -1;
    }
}
