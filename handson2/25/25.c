/*
============================================================================    
Name : 25.c
Author : B Rahul
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 6th Oct, 2023.
============================================================================
*/

#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/time.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(){
    int id;
    key_t k;

    struct ipc_perm msg_perm;
    struct msqid_ds mq;
    
    k = ftok(".",'s');
    id = msgget(k,0);
    msgctl(id,IPC_STAT,&mq);
    
    printf("Permission: %o\n", mq.msg_perm.mode);
    printf("UID: %d\n", mq.msg_perm.uid);
    printf("GID: %d\n", mq.msg_perm.gid);
    printf("Last message sent: %s", ctime(&mq.msg_stime));
    printf("Last message received: %s", ctime(&mq.msg_rtime));
    printf("Last change time: %s", ctime(&mq.msg_ctime));
    printf("Number of messages in queue: %ld\n", mq.msg_qnum);
    printf("Maximum number of bytes: %ld\n", mq.msg_qbytes);
    printf("PID of msgsnd: %d\n", mq.msg_lspid);
    printf("PID of msgrcv: %d\n", mq.msg_lrpid);
    return 0;
}