#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024  // size of shared memory
#define SHM_KEY 1234

int main(){
    key_t key = IPC_PRIVATE; // generate a private key
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); // create shared memory
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    char *shm_address = shamt(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    int i = 0
    while (i < 10){
        printf("Writer: Enter a message to send(num. %d):\n", i + 1);
        char message[SHM_SIZE];
        fgets(message, SHM_SIZE, stdin);
        strcpy(shm_address, message);
        printf("Writer: message sent\n");
    }

    shmdt(shm_address);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
