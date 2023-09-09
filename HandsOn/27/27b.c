/* 
============================================================================
Name : 27b.c
Author : B Rahul
Description : . Write a program to execute ls -Rl by the following system calls
                b. execlp
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
    // Using execlp
    printf("Executing ls -Rl using execlp:\n");
    execlp("ls","ls", "-Rl",(char *) NULL);
    perror("execlp: ");
    return 0;
}
