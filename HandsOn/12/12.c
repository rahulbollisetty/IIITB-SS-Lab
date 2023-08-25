#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
int main(){
    int fd = open("doc.txt",O_WRONLY);
    if(fd==-1){
        printf("Error opening first file\n");
		close(fd);
		return 0;
    }
    int mode = fcntl(fd,F_GETFL);
    mode = mode & O_ACCMODE;
    if(mode == O_RDONLY){
        printf("Opened in read mode\n");
    }
    else if(mode == O_WRONLY){
        printf("Opened in write mode\n");
    }
    else{
        printf("Opened in read write mode\n");
    }
    close(fd);

}