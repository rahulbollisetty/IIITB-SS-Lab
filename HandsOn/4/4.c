#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd = open("../1/demoFile.txt",O_RDWR|O_EXCL,"RW");
    if(fd<0){
        perror("failed to open");
    }
    printf("fd= %d\n",fd);
}