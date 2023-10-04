/*
============================================================================    
Name : 20b.c
Author : B Rahul
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Read from FIFO
Date: 4th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fd = open("fifo_file",O_RDONLY);
    char buff[200];
    read(fd,buff,sizeof(buff));
    printf("Message from first process: %s",buff);
    return 0;
}