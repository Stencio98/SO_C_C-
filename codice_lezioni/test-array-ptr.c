#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * Print the hex content of n bytes, starting from the address p in
 * memory.
 */
void dump_mem(void * p, unsigned int n);

int main()
{
	
        /*
	 * Allocates an array of pointers and the pointed strings
	 * v points to the array of pointers
	 */
	char * v[] = {"01234", "abc", "ABCDEFGH"};

	printf("sizeof(v) = %u\n", (int)sizeof(v));
	printf("v=%p\n", (void *)v);
	printf("v+1=%p\n", (void *)(v+1));
	printf("*v=%p\n", *v);	
	printf("**v=0x%02X\n", **v);
	printf("v[0]=%p\n", v[0]);
	printf("v[1]=%p\n", v[1]);
	printf("v[2]=%p\n", v[2]);

	printf("Printing mem content at v[0]");
	dump_mem(v[0],30);
	printf("Printing mem content at v");
	dump_mem(v,30);
}


void dump_mem(void * p_in, unsigned int n)
{
	unsigned int i;
	unsigned char *p;

	p = (unsigned char *)p_in;
	printf("\np=%p\n", p);
	/* if the last hex digit of p is not 0... */
	if ((long)p & 0xF) {
		/*
		 * ...need to print some heading space
		 *
		 * (void *)((long)p & -15) is
		 *    the address p with last hex digit set = 0x0
		 */
		printf("(%p)", (void *)((long)p & -15));
		for (i=0; i<((long)p & 0xF); i++) {
			printf("   ");
		}
	}
	/* printing 16 bytes per row */
	for (i=0; i<n; i++, p++) {
		/* print the address at the begin of each row */
		if (!(((long)p & 0xF))) {
			printf("(%p)", p);
		}
		/* print the byte */
		printf(" %02X", (unsigned char)*p);
		/* new line if last byte of the row */
		if (((long)p & 0xF) == 0xF) {
			printf("\n");
		}
	}
	printf("\n\n");
}
