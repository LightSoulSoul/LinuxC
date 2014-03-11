#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tmpname[L_tmpnam];
    char *filename;
    FILE *tmpfp;
    char buf[64];

    filename = tmpnam(tmpname);

    printf("file name is : %s\n", filename);
    tmpfp = tmpfile();
    if (tmpfp)
        printf("Opened a temporary file OK!\n");
    else perror("tmpfile");

    fprintf(tmpfp, "Hello World!\n");

    fscanf(tmpfp, "%s", buf);

    printf("%s", buf);
    fclose(tmpfp);
    exit(0);

}
