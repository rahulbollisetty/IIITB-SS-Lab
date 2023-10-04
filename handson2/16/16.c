/*
============================================================================    
Name : 16.c
Author : B Rahul
Description : Write a program to send and receive data from parent to child vice versa. Use two way communication.
Date: 4th Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>

int main(){
	int fd1[2],fd2[2];
	pipe(fd1);
	pipe(fd2);
	if(!fork()){
		close(fd1[0]);
		char buff[100];
		printf("Enter message to parent: ");
		scanf("%[^\n]",buff);
		write(fd1[1],buff,sizeof(buff));
		close(fd2[1]);
		read(fd2[0],buff,sizeof(buff));
		printf("\nMessage from parent: %s\n",buff);
	}
	else{
		close(fd1[1]);
		char buff[200];
		read(fd1[0],buff,sizeof(buff));
		printf("\nMessage from child: %s",buff);
		close(fd2[0]);
		printf("\nEnter message to child: ");
		scanf("%[^\n]",buff);
		write(fd2[1],buff,sizeof(buff));
	}
	return 0;
}
