#include <stdio.h>
#include <string.h>

/*
 * This example reads the command line arguments and print all the
 * strings before and after being sorted.
 */

/* Print n bytes starting from p */
#define MEM_DUMP(p,n) {int j;						\
		for (j=0; j<(n); j++)					\
			printf(" %02X",((unsigned char *)p)[j]);	\
		printf("\n");}

/*
 * Function to sort strings according to alphabetic order
 */
void sort_strings(char* array_char_p[], int length);


int main(int argc, char *argv[])
{
	int i;
	char * p;

	/* Printing the number of arguments */
	printf( "argc = %d\n", argc);
	for(i=0; i<argc; ++i) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	/* Now printing the memory content starting from argv[0] */
	p = argv[0];
	MEM_DUMP(p,100);

	/* Now sorting */
	printf("Now sorting\n");
	sort_strings(argv, argc);

	/* Printing the number of arguments */
	printf( "argc = %d\n", argc);
	for(i=0; i<argc; ++i) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	/* Now printing the memory content starting from argv[0] */
	MEM_DUMP(p,100);
	
	return 0;
}

/*
 * Sorting the strings pointed by array_char_p by alphabetic order.
 * Strings are sorted by sorting the pointers they point to.
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
