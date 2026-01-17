#include "../include/logger.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

void logAction(const char *action, const char *detail)
{
    FILE *fp=fopen("log.txt","a");
    if(fp==NULL)
        return;

    time_t now=time(NULL);
    char *t=ctime(&now);
    t[strlen(t)-1]='\0';   // remove newline

    fprintf(fp,"[%s] %s : %s\n",t,action,detail);
    fclose(fp);
}
