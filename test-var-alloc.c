#include <stdio.h>
#include <stdlib.h>

#define LEN 20

/*
 * Function that returns the string of a number sum of the two inputs
 */
char * sum_and_string(int a, int b)
{
	char * s = malloc(LEN);
	/* static char s[LEN]; */
	/* char s[LEN]; */
	
	snprintf(s, LEN, "%i+%i=%i", a, b, a+b);
	return s;
}

int main()
{
	char * s1, * s2;

	s1 = sum_and_string(10,4);
	s2 = sum_and_string(8,5);
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
}

