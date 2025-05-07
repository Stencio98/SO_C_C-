#include <stdio.h>
#ifdef DYNAMIC
#include <stdlib.h>
#endif

#define SIZE 10

int main()
{
#ifdef DYNAMIC
	int *v;
#else
	int v[SIZE];
#endif
	int i;

	
#ifdef DYNAMIC
	v = malloc(SIZE*sizeof(*v));
#else
	/* Nothing: v is statically allocated */
#endif

	for(i=0; i<SIZE; i++) {
		v[i] = 1<<i;  /* storing something in v */
	}
	for(i=0; i<SIZE; i++) {
		printf("v[%02i] = %i\n", i, v[i]);
	}
#ifdef DYNAMIC
	free(v);
#else
	/* v is statically allocated: no need to free memory */
#endif
}

	
	
