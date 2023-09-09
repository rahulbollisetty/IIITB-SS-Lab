/*
============================================================================
Name : 10.c
Author : B Rahul
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
              bytes (use lseek) and write again 10 bytes.
               a. check the return value of lseek
               b. open the file with od and check the empty spaces in between the data. 

Date: 24th Aug, 2023.
============================================================================
*/

/* 
============================================================================
------------------------------CODE------------------------------------------
============================================================================
*/

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    if(argc!=2){
        printf("2 arguments are required\n");
        return 0;
    }
    int f1 = open(argv[1],O_CREAT|O_EXCL|O_WRONLY, 0777);
    if (f1 == -1)
	{
		printf("Error opening file\n");
		close(f1);
		return 0;
	}
    char buff[] = "Greetings";
    write(f1,buff,sizeof(buff));
    int x = lseek(f1,10,SEEK_CUR);
    if(x)
        printf("Lseek return value: %d\n",x);
    else
        perror("Lseek: ");
    write(f1,buff,sizeof(buff));
}

/* 
============================================================================
------------------------------OUTPUT----------------------------------------
============================================================================
Run : gcc 10.c
Run : ./a.out
    Output: Lseek return value: 20
Run: od -c temp.txt
    Output:
    0000000   G   r   e   e   t   i   n   g   s  \0  \0  \0  \0  \0  \0  \0
    0000020  \0  \0  \0  \0   G   r   e   e   t   i   n   g   s  \0
    0000036
============================================================================
*/