/* 
============================================================================
Name : 30.c
Author : B Rahul
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
                SCHED_RR).
Date: 8th Sept, 2023.
============================================================================
*/

/* 
============================================================================
------------------------------CODE------------------------------------------
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include <time.h>

#define HOUR 14
#define MIN 54
#define SEC 0

#define PATH "/home/fledlucifer/Desktop/iiitb/IIITB-SS-Lab/HandsOn/30/greet"

void script(){
    if(fork()){
    execl(PATH,PATH,(char*)NULL);
    perror("execl failure");
    }
}

int main(){

    if(fork()>0){
        exit(0);
    }

    if (setsid() < 0) {
        perror("setsid failed: ");
        exit(1);
    }
    while(1){

        time_t now;
        struct tm *current;
        time(&now);
        current = localtime(&now);
        // printf("%d - %d - %d\n",current->tm_hour, current->tm_min, current->tm_sec);
        if(current->tm_hour==HOUR &&
            current->tm_min== MIN &&
            current->tm_sec == SEC){
            script();
            sleep(24*3600);
        }
        sleep(1);
    }
} 

/* 
============================================================================
------------------------------OUTPUT----------------------------------------
============================================================================
Run : gcc 30.c
Run : ./a.out
    Output : 
        Greetings, Earthling Developers
============================================================================
*/