/*
============================================================================    
Name : 30a.c
Author : B Rahul
Description : Write a program to create a shared memory.
a. write some data to the shared memory
Date: 9th Oct, 2023.
============================================================================
*/

#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>

int main(){
    int k, shmid;
    char  *data;

    k = ftok(".",'a');
    shmid = shmget(k,1024,IPC_CREAT | 0744);
    data = shmat(shmid,0,0);
    printf("Enter text: ");
    scanf("%[^\n]",data);
    return 0;
}