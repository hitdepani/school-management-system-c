#include "../include/auth.h"
#include "../include/logger.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>   // for getch()

char currentRole[10];

int login()
{
    char username[50];
    char password[50];
    char fileUser[50], filePass[50], fileRole[10];
    int attempts=3;

    while(attempts--)
    {
        printf("\n--- LOGIN ---\n");
        printf("Username: ");
        scanf("%s",username);

        printf("Password: ");
        int i=0;
        char ch;

        while((ch=getch())!='\r'&& ch!='\n')
{
    if(ch=='\b' && i>0)
    {
        i--;
        printf("\b \b");
    }
    else if(ch>=32 && ch<=126)  // printable chars only
    {
        password[i++]=ch;
        printf("*");
    }
}
password[i]='\0';
printf("\n");


        FILE *fp=fopen("users.txt","r");
        if(fp==NULL)
        {
            printf("users.txt not found!\n");
            return 0;
        }

        int success=0;

        while(fscanf(fp,"%s %s %s",fileUser,filePass,fileRole)==3)
        {
            if(strcmp(username,fileUser)==0 &&
               strcmp(password,filePass)==0)
            {
                strcpy(currentRole,fileRole);
                success=1;
                break;
            }
        }
        fclose(fp);

        if(success)
        {
            logAction("LOGIN_SUCCESS",username);
            printf("Login successful!\n");
            return 1;
        }
        else
        {
            logAction("LOGIN_FAILED",username);
            printf("Invalid credentials. Attempts left: %d\n",attempts);
        }
    }
    return 0;
}
