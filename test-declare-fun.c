/* FUNCTION DECLARATION (PROTOTYPE) */
/* Computes the minimum of two integers */
int min(int, int);

/*
 * Try to compile only, with
 * 
 *   gcc -c test-declare-fun.c
 *
 * and try to compile and link with
 *
 *   gcc test-declare-fun.c
 */

int main()
{
	int a;

	a = min(2, -1);
}

#if 0
/* FUNCTION DEFINITION (BODY) */
int min ( int a , int b )
{
	if (a < b ) {
		return a;
	} else {
		return b;
	}
}
#endif
