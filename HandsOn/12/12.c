/*
============================================================================
Name : 12.c
Author : B Rahul
Description : Write a program to find out the opening mode of a file. Use fcntl.

Date: 25th Aug, 2023.
============================================================================
*/

/* 
============================================================================
------------------------------CODE------------------------------------------
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
int main(){
    int fd = open("doc.txt",O_WRONLY);
    if(fd==-1){
        printf("Error opening first file\n");
		close(fd);
		return 0;
    }
    int mode = fcntl(fd,F_GETFL);
    mode = mode & O_ACCMODE;
    if(mode == O_RDONLY){
        printf("Opened in read mode\n");
    }
    else if(mode == O_WRONLY){
        printf("Opened in write mode\n");
    }
    else{
        printf("Opened in read write mode\n");
    }
    close(fd);

}

/* 
============================================================================
------------------------------OUTPUT----------------------------------------
============================================================================
Run : gcc 12.c
Run : ./a.out
    Output: Opened in write mode
============================================================================
*/