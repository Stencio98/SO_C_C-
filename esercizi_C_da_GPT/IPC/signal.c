#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

// Handler function for SIGUSR1
void handle_sigusr1(int sig) {
    printf("Child: received SIGUSR1 (signal %d)\n", sig);
}

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        printf("Child: waiting for SIGUSR1...\n");
        signal(SIGUSR1, handle_sigusr1);
        while (1) {
            printf("Waiting for parent's signal...\n");
            sleep(1);
        }
    }
    else {
        sleep(3);
        printf("Parent: sending SIGUSR1 to child (pid %d)\n", pid);
        kill(pid, SIGUSR1);

        sleep(3);
        printf("Parent: terminating child process\n");
        kill(pid, SIGKILL);
    }

    return 0;
}
