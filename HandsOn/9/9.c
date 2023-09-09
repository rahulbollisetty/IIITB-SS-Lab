/*
============================================================================
Name : 9.c
Author : B Rahul
Description : Write a program to print the following information about a given file.
                a. inode
                b. number of hard links
                c. uid
                d. gid
                e. size
                f. block size
                g. number of blocks
                h. time of last access
                i. time of last modification
                j. time of last change 

Date: 24th Aug, 2023.
============================================================================
*/

/* 
============================================================================
------------------------------CODE------------------------------------------
============================================================================
*/
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


/* 
============================================================================
------------------------------OUTPUT----------------------------------------
============================================================================
Run : gcc 9.c
Run : ./a.out
    Output: 
    I-node number: 8128560
    Link: 1
    UID:  1000      GID: 1000
    File size:  2960
    Block size:  4096
    Number of blocks allocated:  8
    Last file access:         Thu Sep  7 22:45:28 2023
    Last file modification:   Thu Aug 24 23:31:38 2023
    Last status change:       Thu Aug 24 23:31:38 2023
============================================================================
*/