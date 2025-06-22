#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    __pid_t pid;
    pid = fork();
    
    if(pid < 0){
        perror("fork failed");
        exit(0);
    }
    else if(pid == 0){
        printf("child -- pid: %d\n", getpid());
        printf("child -- my parent is: %d\n", getppid());
    }
    else{
        printf("parent -- pid: %d\n", getpid());
        printf("parent -- my parent is: %d\n", getppid());
    }

}