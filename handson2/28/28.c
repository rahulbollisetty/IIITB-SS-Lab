/*
============================================================================    
Name : 28.c
Author : B Rahul
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 6th Oct, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

int main() {
    int msqid;
    key_t k;

    k = ftok(".",'a');
    msqid = msgget(k,0);

    struct msqid_ds msq_info;
    msgctl(msqid, IPC_STAT, &msq_info);
    msq_info.msg_perm.mode = 0660;
    msgctl(msqid, IPC_SET, &msq_info);
    printf("Permissions changed successfully.\n");
    return 0;
}