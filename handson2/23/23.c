/*
============================================================================    
Name : 23.c
Author : B Rahul
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 6th Oct, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
    struct rlimit rlim;
    getrlimit(RLIMIT_NOFILE, &rlim);
    printf("Max number of files that can be opened: %lld\n", (long long)rlim.rlim_cur);

    int fd[2];
    pipe(fd);
    long s = fpathconf(fd[0], _PC_PIPE_BUF);
    printf("Size of the pipe: %ld bytes\n", s);
   
    return 0;
}