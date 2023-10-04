/*
============================================================================    
Name : 19d.c
Author : B Rahul
Description : Create a FIFO file by
d. mkfifo library function
Date: 4th Oct, 2023.
============================================================================
*/

#include<sys/types.h>
#include<sys/stat.h>

int main(){
    mkfifo("mkfifo_file", 0777);
    return 0;
}