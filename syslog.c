#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main()
{
    FILE *f;

    f = fopen("not_here", "r");
    if (!f){
        syslog(LOG_ERR | LOG_USER, "oops - %m\n");
    }
    exit(0);
}

