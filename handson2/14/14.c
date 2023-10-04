/*
============================================================================
Name : 14.c
Author : B Rahul
Description :Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
Date: 4th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main(){
	int fd[2];
	pipe(fd);
	char buf[200];
	printf("Write into pipe: ");
	scanf("%[^\n]",buf);
	write(fd[1],buf,sizeof(buf));
	printf("Reading from pipe: ");
	char data[200];
	read(fd[0],data,sizeof(data));
	printf("%s\n",data);
	return 0;
}
