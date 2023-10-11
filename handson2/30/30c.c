/*
============================================================================    
Name : 30c.c
Author : B Rahul
Description : Write a program to create a shared memory.
c. detach the shared memory
Date: 9th Oct, 2023.
============================================================================
*/

#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>

int main(){
    int k,shmid;
    char* data;
    k = ftok(".",'a');
    shmid = shmget(k, 1024, IPC_CREAT | 0744);
    data = shmat(shmid, 0, 0);

    printf("Data: %s\n",data);
    if(shmdt(data)==-1){
        perror("shmdt");
        return 1;
    }
    printf("Data detached\n");
    return 0;
}   
