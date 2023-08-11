#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
int sl = symlink("demoFile.txt","demoSL");
if(sl<0){
    perror("failed");
    return 1;
}
int hl =link("demoFile.txt","demoHL");
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