/*
============================================================================    
Name : 31a.c
Author : B Rahul
Description : Write a program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore
Date: 10th Oct, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main() {
    int semid;
    key_t key;
    struct sembuf sb;
    key = ftok(".", 'a');
    semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0600);
    sb.sem_num = 0;      
    sb.sem_op = 3;       
    sb.sem_flg = 0;
    semop(semid, &sb, 1);
    printf("Counting semaphore created and initialized with count 3\n");
    return 0;
}