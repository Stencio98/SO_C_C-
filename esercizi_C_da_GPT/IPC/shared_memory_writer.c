#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

#define SHM_SIZE 1024  // size of shared memory
#define SHM_KEY 1234

int main(){
    //key_t key = IPC_PRIVATE; // generate a private key

    // making shared memory
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666); // create shared memory
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    char *shm_address = shamt(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    //making semaphore


    //write 10 messages, then end
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









































#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int sem;
int sem_id = 1;
key_t key;

key = ftok("/virtualpathtosemaphore", 1);
// create a new semaphore
sem = semget(key, 1, IPC_CREAT);
// use sem = semget(key, 1, 0); to attach to an existing semaphore
// flags also contain access rights, to take care to set them appropriately

// increment semaphore
struct sembuf semopinc = {
    .sem_num = 0,
    .sem_op = 1,
    .sem_flg = 0
};
semop(sem, &semopinc, 1);

/* decrement semaphore, may block */
struct sembuf semopdec = {
    .sem_num = 0,
    .sem_op = -1,
    .sem_flg = 0
};
semop(sem, &semopdec, 1);

