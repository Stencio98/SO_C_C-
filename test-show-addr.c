#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



/* Variables allocated over the BSS */
int int_BSS;
char v_BSS[] = "array_in_BSS";

/* 
 * Only the pointer p_BSS is allocated to the BSS, the pointed string may be elsewhere
 */
char * p_BSS = "pointer_in_BSS";  

int main()
{
	int int_stack;
	int * p_var_heap;

	/* Printing addresses of variables over BSS */
	printf("\nVariables over the BSS\n");
	printf("  &int_BSS:     %p\n", (void *)&int_BSS);
	printf("  v_BSS:        %p\n", (void *)v_BSS);
	printf("  &p_BSS:       %p\n", (void *)&p_BSS);
	printf("  p_BSS:        %p (not really onto BSS)\n", (void *)p_BSS);
	
	/* Printing addresses of variables over the stack */
	printf("\nVariables over the stack\n");
	printf("  &int_stack:   %p\n", (void *)&int_stack);
	printf("  &p_var_heap:  %p\n", (void *)&p_var_heap);

	/* Printing addresses of variables over the stack */
	printf("\nVariables over the heap\n");
	p_var_heap = malloc(sizeof(*p_var_heap));
	printf("  p_var_heap:   %p\n", (void *)p_var_heap);

	/* Printing addresses of code */
	printf("\nAddress of code\n");
	printf("  main:         %p\n", (void *)main);

	/* Now view the memory mapping */
	printf("\nView the memory mapping by launching the command\n");
	printf("  less /proc/%d/maps\n", getpid());

	/* Just to wait for the user */
	printf("\nPress ENTER when done\n");
	fgets((char *)p_var_heap, sizeof(*p_var_heap), stdin);

	/* Dynamically allocate memory must be freed */
	free(p_var_heap);
	return 0;
}
  
  
