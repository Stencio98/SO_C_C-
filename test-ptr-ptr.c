/*
 * Allocate dynamically an array p of n pointers. The number n, which
 * is the size of the array is read from stdin.
 *
 * Then allocate dynamically n arrays and store each pointer in p[i]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

/*
 * Print the hex content of n bytes, starting from the address p in
 * memory.
 */
void dump_mem(void * p, unsigned int n);

/*
 * Function to sort strings according to alphabetic order
 */
void sort_strings(char ** array_char_p, int length);

/*
 * Function to print an array of strings
 */
void print_strings(char** array_char_p, int length);

int main()
{
	char **p;       /* Declaration of a pointer to pointers */
	unsigned long n, i, m;
	char s[LEN];

	printf("How many arrays of characters?\n");
	fgets(s, LEN, stdin);
	n = atol(s);
	
	/* Allocate the array of pointers */
	p = malloc(n*sizeof(*p));     /* sizeof(*p)=sizeof(char *) */
	
	/* Allocate all the n arrays */
	for (i=0; i<n; i++) {
		printf("\tSize of the array %lu?\n\t", i);
		fgets(s, LEN, stdin);
		m = atol(s);
		p[i] = malloc(m*sizeof(**p)); /* = malloc(m*sizeof(*p[i])); */
		printf("\tContent of the array %lu (string)?\n\t", i);
		fgets(p[i], m, stdin);
	}

	/* Print memory content of array of pointers */
	printf("\nMemory content of the array of pointers");
	dump_mem(p, n*sizeof(*p));

	/* Print memory content of all the n arrays of chars */
	printf("\nMemory content of each array of char");
	for (i=0; i<n; i++) {
		/*
		 * Printing 20 bytes: we don't know how much memory
		 * was allocated
		 */
		dump_mem(p[i], 16);
	}

	printf("\nContent before sorting\n");
	print_strings(p, n);
	
	printf("\nContent after sorting\n");
	sort_strings(p, n);
	print_strings(p, n);
	
	/* De-allocate all the n arrays... */
	for (i=0; i<n; i++) {
		free(p[i]);
	}

	/*
	 * ... and after de-allocate p.
	 *
	 * IMPORTANT: DO NOT de-allocate p first, otherwise the areas
	 * pointed by p[i] are lost!!
	 */
	free(p);
}


void dump_mem(void * p_in, unsigned int n)
{
	unsigned int i;
	char *p;

	p = (char *)p_in;
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
		printf(" %02hhX", *p);
		/* new line if last byte of the row */
		if (((long)p & 0xF) == 0xF) {
			printf("\n");
		}
	}
	printf("\n\n");
}

/*
 * Sorting the strings pointed by array_char_p by alphabetic order.
 * Strings are sorted by sorting the pointers they point to. 
 * 
 * REMARK: the function sort_strings was declared to have the 1st
 * argument as (char **), but the compiler is happy with 
 * (char * array_char_p[]). Arrays a pointers are the same when 
 * passed as function arguments
 */
void sort_strings(char* array_char_p[], int length)
{
	int i, j;
	char* tmp;
	for( i=0; i< length; i++ ) {
		for(j=i+1; j< length; j++) {
			if( strcmp(array_char_p[i], array_char_p[j]) > 0 ) {
				tmp = array_char_p[i];
				array_char_p[i] = array_char_p[j];
				array_char_p[j] = tmp;
			}
		}
	}
}

void print_strings(char* array_char_p[], int length)
{
	int i;

	for (i=0; i<length; i++) {
		printf("%s\n", array_char_p[i]);
	}
}
