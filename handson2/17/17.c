/*
============================================================================    
Name : 17a.c
Author : B Rahul
Description : Write a program to execute ls -l | wc.
a. use dup
Date: 4th Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
int main(){
    int fd[2];
    pipe(fd);
    if(!fork()){
        close(1);
        close(fd[0]);
        dup(fd[1]);
        execlp("ls","ls","-l",NULL);
    }
    else{
        close(0);
        close(fd[1]);
        dup(fd[0]);
        execlp("wc","wc",NULL);
    }
    wait(0);
    return 0;
}