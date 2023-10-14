/*
============================================================================    
Name : 33_server.c
Author : B Rahul
Description : Write a program to communicate between two machines using socket.
Server program
Date: 11th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <unistd.h>
#include <string.h>

int main(){
    int sd;
    sd = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(16000);
    serv.sin_addr.s_addr = INADDR_ANY;

    bind(sd,(struct sockaddr*) &serv,sizeof(serv));

    listen(sd,5);

    int cl;
    cl = accept(sd,NULL,NULL);
    char msg[] = "Wassap bro\n";
    write(cl,msg,strlen(msg));

    close(sd);
    return 0;
}
