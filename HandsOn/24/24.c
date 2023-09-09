/* 
============================================================================
Name : 24.c
Author : B Rahul
Description : Write a program to create an orphan process.
Date: 7th Sept, 2023.
============================================================================
*/

/* 
============================================================================
------------------------------CODE------------------------------------------
============================================================================
*/
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
int main(){
    int id = fork();
    if(id==0){
        printf("Child process, my ID: %d and parent process ID: %d\n",id,getppid());
        sleep(10);
        printf("After sleep of child process, Parent process ID: %d\n",getppid());
        }
    else{
        printf("Parent process, my ID: %d and child process ID: %d\n",getpid(),id);
        printf("Parent process exiting......\n");
        exit(0);
    }
}

/* 
============================================================================
------------------------------OUTPUT----------------------------------------
============================================================================
Run : gcc 24.c
Run : ./a.out
    Output : 
    Parent process, my ID: 11518 and child process ID: 11519
    Parent process exiting......
    Child process, my ID: 0 and parent process ID: 11518
    After sleep of child process, Parent process ID: 1670
============================================================================
*/

