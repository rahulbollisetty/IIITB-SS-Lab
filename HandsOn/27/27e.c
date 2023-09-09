/* 
============================================================================
Name : 27e.c
Author : B Rahul
Description : . Write a program to execute ls -Rl by the following system calls
                e. execvp
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
    // Using execvp
    printf("Executing ls -Rl using execvp:\n");
    char *argv[] = { "ls", "-Rl", NULL };
    execvp("ls", argv);
    perror("execvp: ");
    return 0;
}

