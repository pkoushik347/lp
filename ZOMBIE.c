#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

    int pid = fork();
    if (pid ==  0){
        printf("child process %d\n",getpid());
	exit(0);
     }
    else {
        wait(0);
	sleep(10);
    	printf("Parent process %d\n",getppid());
       }
    return 0;
}
