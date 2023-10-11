/*
============================================================================    
Name : 33_cli.c
Author : Siddharth V. Pillai
Description : Write a program to communicate between two machines using socket.
client program
Date: 9th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <unistd.h>
int main(){
    int nsd;
    nsd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(16000); 
    serv.sin_addr.s_addr = INADDR_ANY;

    connect(nsd, (struct sockaddr *)&serv, sizeof(serv));

    char resp[256];
    read(nsd,resp,256);

    printf("Data from server: %s\n",resp);
    close(nsd);
    return 0;
}