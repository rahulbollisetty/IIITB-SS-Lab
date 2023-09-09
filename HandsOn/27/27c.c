/* 
============================================================================
Name : 27c.c
Author : B Rahul
Description : . Write a program to execute ls -Rl by the following system calls
                c. execle
Date: 7th Sept, 2023.
============================================================================
*/

/* 
============================================================================
------------------------------CODE------------------------------------------
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // Using execlv
    printf("Executing ls -Rl using execle:\n");
    char *envp[] = {NULL};
    execle("/bin/ls", "ls","-Rl",(char *) NULL,envp);
    perror("execle: ");
    return 0;
}
