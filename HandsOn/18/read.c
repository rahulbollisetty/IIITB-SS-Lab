/*
============================================================================
Name : 18b.c
Author : B Rahul
Description :  Write a program to perform Record locking.
                b. Implement read lock
                Create three records in a file. Whenever you access a particular record, first lock it then modify/access
                to avoid race condition.
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
    int fd = open("db.txt",O_RDWR);
        if(fd==-1){
        printf("Error opening file\n(or)Try deleteing the ticket_number file\n");
		close(fd);
		return 0;
    }
    int x;
    write(1,"Enter the record number to access{1,2,3}: ",43);
    scanf(" %d",&x);
    char buf[11];
    struct flock lock;
    lock.l_type    = F_RDLCK;   
    lock.l_start   = (x-1)*sizeof(buf);
    lock.l_whence  = SEEK_SET;
    lock.l_len     = sizeof(buf); 
    lock.l_pid = getpid();
    printf("Before the critical section\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Inside the critical section\n");
    write(1,"Record Data: ",14);
    lseek(fd,(x-1)*sizeof(buf),SEEK_SET);
    read(fd,&buf,sizeof(buf));
    write(1,&buf,sizeof(buf));
    write(1,"\n",2);
    printf("Press Enter to unlock\n");
    getchar();
    getchar();
    lock.l_type =F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    write(1,"Closing\n",9);
    close(fd);
}

/* 
============================================================================
------------------------------OUTPUT----------------------------------------
============================================================================
Run : gcc 18b.c -o read
Run : ./read
    Output : 
        Enter the record number to access{1,2,3}: 1
        Before the critical section
        Inside the critical section
        Record Data: 15
        Press Enter to unlock
        Closing
============================================================================
*/