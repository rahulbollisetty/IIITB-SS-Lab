#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>

int main(){
    int id;
    key_t k;
    struct msg{
        long int mtype;
        char message[80];
    }mq;

    k = ftok(".",'a');
    id = msgget(k,IPC_CREAT | 0666);
    printf("Enter message type: ");
    scanf("%ld",&mq.mtype);

    printf("\nEnter message: ");
    getchar();
    scanf("%[^\n]",mq.message);
    size_t size = strlen(mq.message);

    msgsnd(id,&mq,size,0);
    printf("Message sent successfully to message queue with key %d\n", id);

    return 0;
}