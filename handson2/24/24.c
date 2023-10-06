/*
============================================================================    
Name : 24.c
Author : B Rahul
Description : Write a program to create a message queue and print the key and message queue id.
Date: 6th Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>

int main(){
    int id;
    key_t k;
    k = ftok(".",'s');
    id = msgget(k,IPC_CREAT | IPC_EXCL|0744);
    printf("Key: %d",k);
    printf("\nMsg queue id: %d",id);
    return 0;
}