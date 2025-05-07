#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


#define NUM_FORKS  4  /* maybe.... */

int main() {
	int i;
	unsigned int my_pid, my_ppid, value;
	
	/* How many processes are really generated? */
	for (i=0; i<NUM_FORKS; i++) {
		
		value = fork();
		my_pid = getpid();
		my_ppid = getppid();
		/* How many printed lines? */
		printf("PID=%6d,  PPID=%6d,  i=%d, fork_value=%d\n",
		       my_pid, my_ppid, i, value);
		/*sleep(1); */
	}
	exit(EXIT_SUCCESS);
}
