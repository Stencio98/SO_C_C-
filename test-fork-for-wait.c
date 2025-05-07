#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define DONT_WAIT
#define NUM_ITER  4

int main() {
	int i, num_kids = 0;
	unsigned int my_pid, my_ppid, value;

	/*
	 * Removing buffering of stdout to better understand what's
	 * going on
	 */
	setvbuf(stdout, NULL, _IONBF, 0);
	
	/* How many processes are really generated? */
	for (i=0; i<NUM_ITER; i++) {
		
		value = fork();
		if (value) {
			num_kids++;
		} else {
			num_kids = 0;
		}
		my_pid = getpid();
		my_ppid = getppid();
		/* How many printed lines? */
		printf("PID=%6d,  PPID=%6d,  i=%d, fork_value=%d\n",
		       my_pid, my_ppid, i, value);
		/*sleep(1); */
	}
#ifdef DONT_WAIT
	/* 
	 * Don't wait for child processes: the parent may exit before
	 * the kids
	 */
	printf("PID=%6d: I'm terminating. Don't know about my %d child processes\n",
	       my_pid, num_kids);
#else
	/*
	 * All processes wait for the completion of all child
	 * processes.
	 */
	while(wait(NULL) != -1);
	printf("PID=%6d: I and all %d child processes terminated\n",
	       my_pid, num_kids);
#endif
}
