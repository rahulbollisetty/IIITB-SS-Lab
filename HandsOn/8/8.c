/*
============================================================================
Name : 8.c
Author : B Rahul
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
              Close the file when end of file is reached. 

Date: 18th Aug, 2023.
============================================================================
*/

/* 
============================================================================
------------------------------CODE------------------------------------------
============================================================================
*/

#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char *argv[]){
    if(argc!=2){
        printf("2 arguments are required\n");
        return 0;
    }
    int f1 = open(argv[1],O_RDONLY);
    if (f1 == -1)
	{
		printf("Error opening first file\n");
		close(f1);
		return 0;
	}
    char buff;
    char *temp = malloc(1);
    int i=0;
    while(read(f1,&buff,1)){
        if(buff != '\n'){
            temp = (char *)realloc(temp,1+i);
            temp[i] = buff;
            i++;
        }
        else{
            write(1,temp,i);
            write(1,"\n",1);
            // free(temp);
            i=0;
        }
    }
    close(f1);
    
    return 0;
}

/* 
============================================================================
------------------------------OUTPUT----------------------------------------
============================================================================
Run : gcc 8.c
Run : ./a.out
    Output: 
        Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed maximus turpis magna, 
        ut placerat nulla maximus quis. Aenean imperdiet ut ipsum eu tempus. Integer dictum lectus arcu.
============================================================================
*/