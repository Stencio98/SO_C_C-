#include <stdio.h>


int main()
{
	short y_sign = -1;
	unsigned short n_sign;
/*
	int y_sign = -1;
	unsigned int n_sign;
*/
	
	n_sign = y_sign; /* the compiler does not complain */
	printf("PRINTING ABOUT SIGNED VARIABLE\n");
	printf("  y_sign:     %%hhd=%hhd, %%hhu=%hhu\t\t(%%hh ==> read expression as a char)\n", y_sign, y_sign);
	printf("  y_sign:     %%hd=%hd, %%hu=%hu\t\t(%%h ==> read expression as a short)\n", y_sign, y_sign);
	printf("  y_sign:     %%d=%d, %%u=%u\t(nothing ==> read expression as a int)\n", y_sign, y_sign);
	printf("  y_sign > 0: %d\n", y_sign > 0);
	printf("PRINTING ABOUT UNSIGNED VARIABLE\n");
	printf("  n_sign:     %%hhd=%hhd, %%hhu=%hhu\t\t(%%hh ==> read expression as a char)\n", n_sign, n_sign);
	printf("  n_sign:     %%hd=%hd, %%hu=%hu\t\t(%%h ==> read expression as a short)\n", n_sign, n_sign);
	printf("  n_sign:     %%d=%d, %%u=%u\t(nothing ==> read expression as a int)\n", n_sign, n_sign);
	printf("  n_sign > 0: %d\n", n_sign > 0);
	printf("COMPARING SIGNED AND UNSIGNED VARIABLE\n");
	printf("  y_sign == n_sign: %d\n", y_sign == n_sign);

	return 0;
}
