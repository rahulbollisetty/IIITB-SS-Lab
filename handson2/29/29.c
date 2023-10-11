/*
============================================================================    
Name : 29.c
Author : B Rahul
Description : Write a program to remove the message queue. 
Date: 9th Oct, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

int main(){
    int msqid;
    key_t k;
    k = ftok(".",'a');
    msqid = msqid = msgget(k, 0);
    msgctl(msqid, IPC_RMID, NULL);
    printf("Queue removed successfully\n");
    return 0;
}