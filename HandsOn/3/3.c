#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd = open("File.txt",O_CREAT);
    if(fd<0){
        perror("failed to open");
    }
    printf("fd= %d\n",fd);
}