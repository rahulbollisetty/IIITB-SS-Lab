#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]){
    if(argc!=2){
        printf("2 arguments are required\n");
        return 0;
    }
    struct stat info;
    if (stat(argv[1], &info) == -1) {
               perror("stat: ");
               return 0;
           }
    else{
        printf("I-node number: %ju\n",(__uintmax_t)info.st_ino);
        printf("Link: %ju\n",info.st_nlink);
        printf("UID:  %ju\tGID: %ju\n",(__uintmax_t)info.st_uid,(__uintmax_t)info.st_gid);
        printf("File size:  %ju\n",(__uintmax_t)info.st_size);
        printf("Block size:  %ju\n",(__uintmax_t)info.st_blksize);
        printf("Number of blocks allocated:  %ju\n",(__uintmax_t)info.st_blocks);
        printf("Last file access:         %s", ctime(&info.st_atime));
        printf("Last file modification:   %s", ctime(&info.st_mtime));
        printf("Last status change:       %s", ctime(&info.st_ctime));

    }
}