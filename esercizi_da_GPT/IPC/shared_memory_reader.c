#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

#define SHM_SIZE 1024
#define SHM_KEY 1234

int main() {
    // Obtain the shared memory segment ID created by the writer
    int shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory
    char *shm_address = shmat(shmid, NULL, 0);
    if (shm_address == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Reader process started. Waiting for messages...\n");

    // Read messages in a loop
    while(1) {
        // Read the message
        printf("Reader: Message %d: %s", i + 1, shm_address);
        // Here, you could implement synchronization (e.g., semaphores)
    }

    // Detach from shared memory
    shmdt(shm_address);

    // Optionally, remove the shared memory segment
    // shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
