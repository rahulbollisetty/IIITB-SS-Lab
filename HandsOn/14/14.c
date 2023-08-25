#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include<sys/types.h>
int main(int argc, char **argv)
{
    if(argc!=2){
        printf("2 arguments are required\n");
        return 0;
    }
    struct stat info;
    stat(argv[1],&info);
    printf("File type: ");
    switch (info.st_mode & __S_IFMT) {
    case S_IFBLK:  printf("block device\n");            break;
    case S_IFCHR:  printf("character device\n");        break;
    case S_IFDIR:  printf("directory\n");               break;
    case S_IFIFO:  printf("FIFO/pipe\n");               break;
    case S_IFLNK:  printf("symlink\n");                 break;
    case S_IFREG:  printf("regular file\n");            break;
    case S_IFSOCK: printf("socket\n");                  break;
    default:       printf("unknown?\n");                break;
    }
}