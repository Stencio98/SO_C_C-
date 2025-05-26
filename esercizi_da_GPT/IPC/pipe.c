#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    __pid_t pid;
    int pipefd[2];
    char buffer[256];

    if (pipe(pipefd) == -1) {
        perror("pipe error");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork error");
        return 1;
    } else if (pid == 0) {
        // child process
        close(pipefd[1]); //close write side
        read(pipefd[0], buffer, sizeof(buffer));
        printf("read from child: %s\n", buffer);
        close(pipefd[0]);
    } else {
        //parent process
        close(pipefd[0]); //close read side 
        const char *message = "hello from your dad \npipe are unidirectinal, to send me a reply we need another one pipe or something else like shared memory";
        write(pipefd[1], message, strlen(message)+1);
        close(pipefd[1]);

        wait(NULL);
    }
}
