#include <stdio.h>

int main() {
	double f = 0.2;
	char * p_chr;
	int i;
	
	printf("Variable f of type double\n");
	printf("[%p]: %f, sizeof(f)=%d, sizeof(&f)=%d\n",
	       &f, f, (int)sizeof(f), (int)sizeof(f));

	printf("\nPrinting the same content as array of bytes\n");
	p_chr = (char *)&f;
	for(i=0; i<sizeof(f); i++) {
		printf("[%p]: %02hhX\n", p_chr+i, *(p_chr+i));
	}
}
