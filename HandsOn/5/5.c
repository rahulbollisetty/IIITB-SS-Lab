#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd1 = open("File1.txt",O_CREAT,0777);
    int fd2 = open("File2.txt",O_CREAT,0777);
    int fd3 = open("File3.txt",O_CREAT,0777);
    int fd4 = open("File4.txt",O_CREAT,0777);
    int fd5 = open("File5.txt",O_CREAT,0777);
    while(1);

}