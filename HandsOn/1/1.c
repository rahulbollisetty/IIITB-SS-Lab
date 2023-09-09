/* 
============================================================================
Name : 1.c
Author : B Rahul
Description : Create the following types of a files using (i) shell command (ii) system call
                a. soft link (symlink system call)
                b. hard link (link system call)
                c. FIFO (mkfifo Library Function or mknod system call)
                
Date: 11th Aug, 2023.
============================================================================
*/

/* 
============================================================================
------------------------------CODE------------------------------------------
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
    int sl = symlink("demoFile.txt","SL");
    if(sl<0){
        perror("failed");
        return 1;
    }
    int hl =link("demoFile.txt","HL");
    if(hl<0){
        perror("failed");
        return 1;
    }
    int e = mknod("tempfifo",S_IFIFO|0666, 0);
    if(e<0){
        perror("fifo");
    }
return 0;
}


/* 
============================================================================
------------------------------OUTPUT----------------------------------------
============================================================================
Run : gcc 1.c
Run : cat demoFile.txt
    Output : This is a demo file

Run : echo "Hello" >> HL
Run : echo "How r u?" >> SL
Run : cat demoFile.txt
    Output: This is a demo file
            Hello
            How r u?

Run: echo "hello world" > tempfifo
Run: cat tempfifo
Output: hello world
============================================================================
*/
