/* 
============================================================================
Name : 25.c
Author : B Rahul
Description : Write a program to create three child processes. The parent should wait for a particular child (use
                waitpid system call).
Date: 7th Sept, 2023.
============================================================================
*/

/* 
============================================================================
------------------------------CODE------------------------------------------
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t child1,child2,child3;
    child1=fork();
    if(child1==0){
        printf("Child 1 (PID: %d) is running.\n", getpid());
        exit(0);
    }
    else{
        child2=fork();
        if(child2==0){
            printf("Child 2 (PID: %d) is running.\n", getpid());
            exit(0);
        }
        else{
            child3 = fork();
            if(child3==0){
                printf("Child 3 (PID: %d) is running.\n", getpid());
                exit(0);
            }
            else{
                printf("Parent (PID: %d) is waiting for Child 2 (PID: %d) to complete.\n", getpid(), child2);
                int status;
                int child_pid = waitpid(child2,&status,0);
                if (WIFEXITED(status)) {
                    printf("Parent: Child 2 (PID: %d) exited with status %d.\n", child2, WEXITSTATUS(status));
                }
            }
        }
    }
}
/* 
============================================================================
------------------------------OUTPUT----------------------------------------
============================================================================
Run : gcc 25.c
Run : ./a.out
    Output : 
        Child 1 (PID: 143808) is running.
        Parent (PID: 143807) is waiting for Child 2 (PID: 143809) to complete.
        Child 2 (PID: 143809) is running.
        Child 3 (PID: 143810) is running.
        Parent: Child 2 (PID: 143809) exited with status 0.
============================================================================
*/
