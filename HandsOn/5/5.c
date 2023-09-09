/*
============================================================================
Name : 5.c
Author : B Rahul
Description :  Write a program to create five new files with infinite loop. Execute the program in the background
               and check the file descriptor table at /proc/pid/fd 

Date: 11th Aug, 2023.
============================================================================
*/

/* 
============================================================================
------------------------------CODE------------------------------------------
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd1 = open("File1.txt",O_CREAT,0777);
    int fd2 = open("File2.txt",O_CREAT,0777);
    int fd3 = open("File3.txt",O_CREAT,0777);
    int fd4 = open("File4.txt",O_CREAT,0777);
    int fd5 = open("File5.txt",O_CREAT,0777);
    while(1);

}

/* 
============================================================================
------------------------------OUTPUT----------------------------------------
============================================================================
Run : gcc 5.c
Run : ./a.out
Run : ll /proc/4907/fd
Output: 

total 0
dr-x------ 2 fledlucifer fledlucifer 12 Sep  9 06:15 ./
dr-xr-xr-x 9 fledlucifer fledlucifer  0 Sep  9 06:15 ../
lrwx------ 1 fledlucifer fledlucifer 64 Sep  9 06:15 0 -> /dev/pts/0
lrwx------ 1 fledlucifer fledlucifer 64 Sep  9 06:15 1 -> /dev/pts/0
lr-x------ 1 fledlucifer fledlucifer 64 Sep  9 06:15 103 -> /snap/code/137/usr/share/code/v8_context_snapshot.bin
lrwx------ 1 fledlucifer fledlucifer 64 Sep  9 06:15 2 -> /dev/pts/0
lr-x------ 1 fledlucifer fledlucifer 64 Sep  9 06:15 3 -> /home/fledlucifer/Desktop/iiitb/IIITB-SS-Lab/HandsOn/5/File1.txt*
l-wx------ 1 fledlucifer fledlucifer 64 Sep  9 06:15 38 -> /home/fledlucifer/.config/Code/logs/20230909T055705/ptyhost.log
lrwx------ 1 fledlucifer fledlucifer 64 Sep  9 06:15 39 -> 'socket:[35896]'
lr-x------ 1 fledlucifer fledlucifer 64 Sep  9 06:15 4 -> /home/fledlucifer/Desktop/iiitb/IIITB-SS-Lab/HandsOn/5/File2.txt*
lr-x------ 1 fledlucifer fledlucifer 64 Sep  9 06:15 40 -> /snap/code/137/usr/share/code/resources/app/node_modules.asar
lr-x------ 1 fledlucifer fledlucifer 64 Sep  9 06:15 5 -> /home/fledlucifer/Desktop/iiitb/IIITB-SS-Lab/HandsOn/5/File3.txt*
lr-x------ 1 fledlucifer fledlucifer 64 Sep  9 06:15 6 -> /home/fledlucifer/Desktop/iiitb/IIITB-SS-Lab/HandsOn/5/File4.txt*
lr-x------ 1 fledlucifer fledlucifer 64 Sep  9 06:15 7 -> /home/fledlucifer/Desktop/iiitb/IIITB-SS-Lab/HandsOn/5/File5.txt*

============================================================================
*/