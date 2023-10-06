/*
============================================================================    
Name : 21b.c
Author : B Rahul
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
second process
Date: 6th Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
    int fd1 = open("f1",O_RDONLY);
    int fd2 = open("f2",O_WRONLY);
    char buff[200];

    read(fd1,buff,sizeof(buff));
    printf("\nMessage from 1st process: %s",buff);
    
    printf("\nEnter message for 1st process: ");
    scanf("%[^\n]",buff);
    write(fd2,buff,sizeof(buff));
    return 0;
}