/*
============================================================================    
Name : 19c.c
Author : B Rahul
Description : Create a FIFO file by
c. mknod system call
Date: 4th Oct, 2023.
============================================================================
*/

#include<sys/stat.h>
#include<fcntl.h>
int main(){
    mknod("mknod_file",S_IFIFO | 0666,0);
    return 0;
}