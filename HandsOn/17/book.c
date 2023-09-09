/*
============================================================================
Name : 17.c
Author : B Rahul
Description :   Write a program to simulate online ticket reservation. Implement write lock
                Write a program to open a file, store a ticket number and exit. Write a separate program, to
                open the file, implement write lock, read the ticket number, increment the number and print
                the new ticket number then close the file.
Date: 25th Aug, 2023.
============================================================================
*/

/* 
============================================================================
------------------------------CODE------------------------------------------
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int fd = open("ticket_number.txt",O_RDWR);
        if(fd==-1){
        printf("Error opening file\n(or)Try deleteing the ticket_number file\n");
		close(fd);
		return 0;
    }
    char buf[11];
    struct flock lock;
    lock.l_type    = F_WRLCK;   
    lock.l_start   = 0;
    lock.l_whence  = SEEK_SET;
    lock.l_len     = sizeof(buf); 
    lock.l_pid = getpid();
    fcntl(fd, F_SETLKW, &lock);
    write(1,"Number of seats left: ",23);
    read(fd,&buf,sizeof(buf));
    write(1,&buf,sizeof(buf));
    write(1,"\n",2);
    int i = atoi(buf);
    if(i<=0){
        write(1,"Not Enough tickets to book\n",28);
        return 0;
    }
    write(1,"Press Enter to Confirm",23);
    getchar();
    i--;
    sprintf(buf, "%d\n", i);
    write(1,"Your Ticket number: ",21);
    write(1,&buf,sizeof(buf));
    write(1,"\n",2);
    lseek(fd,0,SEEK_SET);
    write(fd,&buf,strlen(buf));
    lock.l_type =F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    write(1,"Ticket booked\n",15);
    close(fd);
}

/* 
============================================================================
------------------------------OUTPUT----------------------------------------
============================================================================
Run : gcc book.c -o book
Run : ./book
    Output : 
        Number of seats left: 10

        Press Enter to Confirm
        Your Ticket number: 9

        Ticket booked
============================================================================
*/