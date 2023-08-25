#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    if(argc!=3){
        printf("3 arguments are required\n");
        return 0;
    }
    int f1 = open(argv[1],O_RDONLY);
    int f2 = open(argv[2],O_CREAT|O_EXCL|O_WRONLY, 0555);
    if (f1 == -1)
	{
		printf("Error opening first file\n");
		close(f1);
		return 0;
	}
    char buff;
    while(read(f1,&buff,1)){
        write(f2,&buff,1);
    }

    printf("Successfully copied \n");
    close(f1);
    close(f2);

    return 0;
}