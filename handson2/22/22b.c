/*
============================================================================    
Name : 22b.c
Author : B Rahul
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
process for reading
Date: 6th Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/select.h>

int main(){
    int fd = open("FIFO",O_RDONLY);
    fd_set rfds;
    struct timeval tv;
    char buff[200];
    FD_ZERO(&rfds);
    FD_SET(fd,&rfds);

    tv.tv_sec = 10;
    tv.tv_usec = 0;
    
    int retval = select(fd+1,&rfds,NULL,NULL,&tv);
    read(fd,buff,sizeof(buff));
    if(!retval){
        printf("Data not available within 10s.");
    }
    else{
        printf("Message from first process: %s\n",buff);
    }
    return 0;
}