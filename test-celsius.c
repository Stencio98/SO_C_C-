#include <stdio.h>

/* stampa la tabella Fahrenheit-Celsius per fahr=0, 20, 40, ..., 300 */
int main() {
	int fahr, cels1, cels2, cels3, cels5;
	double cels4;
	
	printf("fahr\tcels1\tcels2\tcels3\tcels4\tcels5\n");
	for (fahr = 0; fahr <= 320; fahr += 40) {

		/* int expression assigned to int var:
		 * no conversion 
		 */
		cels1 = ((fahr - 32) * 5) / 9;

		/* int expression assigned to int var:
		 * no conversion and 5/9 = 0 
		 */
		cels2 = (fahr - 32) * (5/9);

		/* automatic conversion of the expression in float
		 * then assignment conversion float => int due
		 */
		cels3 = (fahr - 32) * (5/9.0);

		/* integer expression which equals zero. 
		 * Then assigned to double
		 */
		cels4 = (fahr - 32) * (5/9);

		/* explicit conversion to double.
		 * Then assigned to int
		 */
		cels5 = (fahr - 32) * ((double)5/9);
		printf("%d\t%d\t%d\t%d\t%.3f\t%d\n",
		       fahr, cels1, cels2, cels3, cels4, cels5);
	}
	return 0;
}
