#include <stdio.h>
#include <string.h>

#include "login.h"

int login()
{
    char username[30];
    char password[30];

    char fileUsername[30];
    char filePassword[30];

    FILE *fp;

    fp = fopen("admin.txt", "r");

    if(fp == NULL)
    {
        printf("\nError: Cannot open admin.txt\n");
        return 0;
    }

    printf("\n================================");
    printf("\n       ADMIN LOGIN");
    printf("\n================================\n");

    printf("Username : ");
    scanf("%s", username);

    printf("Password : ");
    scanf("%s", password);

    fscanf(fp, "%s %s", fileUsername, filePassword);

    fclose(fp);

    if(strcmp(username, fileUsername) == 0 &&
       strcmp(password, filePassword) == 0)
    {
        printf("\nLogin Successful!\n");
        return 1;
    }

    printf("\nInvalid Username or Password!\n");

    return 0;
}