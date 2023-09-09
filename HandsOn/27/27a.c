/* 
============================================================================
Name : 27a.c
Author : B Rahul
Description : Write a program to execute ls -Rl by the following system calls
                a. execl
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
    // Using execl
    printf("Executing ls -Rl using execl:\n");
    execl("/usr/bin/ls", "ls", "-Rl",(char *) NULL);
    perror("execl: ");
    return 0;
}
