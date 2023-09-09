/* 
============================================================================
Name : 27d.c
Author : B Rahul
Description : . Write a program to execute ls -Rl by the following system calls
                d. execv
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
    // Using execv
    printf("Executing ls -Rl using execv:\n");
    char *argv[] = { "ls", "-Rl", NULL };
    execv("/usr/bin/ls", argv);
    perror("execv: ");
    return 0;
}

