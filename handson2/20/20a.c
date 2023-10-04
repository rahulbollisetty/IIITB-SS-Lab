/*
============================================================================    
Name : 20a.c
Author : B Rahul
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Write into FIFO
Date: 4th Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
    int fd = open("fifo_file",O_WRONLY);
    char buff[200];
    printf("Enter message for 2nd process: ");
    scanf("%[^\n]",buff);
    write(fd,buff,sizeof(buff));
}