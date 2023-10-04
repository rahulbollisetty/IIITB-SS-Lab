/*
============================================================================    
Name : 17c.c
Author : B Rahul
Description : Write a program to execute ls -l | wc.
c. use fcntl
Date: 4th Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<fcntl.h>
int main(){
    int fd[2];
    pipe(fd);
    if(!fork()){
        close(1);
        close(fd[0]);
        fcntl(fd[1],F_DUPFD,1);
        execlp("ls","ls","-l",NULL);
    }
    else{
        close(0);
        close(fd[1]);
        fcntl(fd[0],F_DUPFD,0);
        execlp("wc","wc",NULL);
    }
    wait(0);
    return 0;
}