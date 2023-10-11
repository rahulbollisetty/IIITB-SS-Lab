/*
============================================================================    
Name : 30d.c
Author : B Rahul
Description : Write a program to create a shared memory.
d. remove the shared memory
Date: 9th Oct, 2023.
============================================================================
*/

#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int k, shmid;

    k = ftok(".", 'a');
    shmid = shmget(k, 1024, IPC_CREAT | 0744);
    shmctl(shmid, IPC_RMID, NULL);
    printf("Shared memory removed\n");
    return 0;
}
