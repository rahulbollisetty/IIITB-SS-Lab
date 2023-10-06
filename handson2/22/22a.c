/*
============================================================================    
Name : 22a.c
Author : B Rahul
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
process for writing
Date: 6th Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(){
    int fd = open("FIFO",O_WRONLY);
    char buff[200];
    printf("Enter message for 2nd process: ");
    scanf("%[^\n]",buff);
    write(fd,buff,sizeof(buff));
    return 0;
}