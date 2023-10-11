/*
============================================================================    
Name : 31a.c
Author : B Rahul
Description : Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
Date: 10th Oct, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main(){
    int semid;
    key_t k;
    struct sembuf sb;
    k = ftok(".", 'a');
    semid = semget(k, 1, IPC_CREAT | IPC_EXCL | 0600);
    sb.sem_num = 0;      
    sb.sem_op = 1;       
    sb.sem_flg = 0;
    semop(semid, &sb, 1);
    printf("Binary semaphore created and initialized\n");
}