#include <stdio.h>

int main() {
    // Integer variables
    int numInt = 42;
    int numOct = 42; // same value, to demonstrate octal
    int numHex = 255;
    
    // Floating point variables
    double numFloat = 3.14159;
    double numExp = 12345.6789;
    
    // String and character
    char message[] = "Hello, World!";
    char ch = 'A';

    // Printing integers
    printf("%d\n", numInt);     // Print as decimal
    printf("%o\n", numInt);     // Print as octal
    printf("%X\n", numInt);     // Print as hexadecimal (uppercase)

    // Printing floating points
    printf("%e\n", numExp);     // Scientific notation
    printf("%f\n", numFloat);   // Fixed-point notation

    // Printing string
    printf("%s\n", message);

    // Printing character
    printf("%c\n", ch);
	
	printf("\tsecond_test:\n");
	
	// Printing a new line
    printf("This is a new line:\n");

    // Printing a tab
    printf("This line is tabbed:\tSee?\n");

    // Printing a double quote
    printf("Printing a double quote: \"Hello\"\n");

    // Printing a single quote
    printf("Printing a single quote: \'Hello\'\n");
 
    // Printing a backslash
    printf("This is a backslash: \\\n");

    // Printing a percent sign
    printf("Percent sign: %%\n");

    // Printing a Unicode character using \uXXXX
    // Example: Unicode for 'Ω' (Omega) is U+03A9
    printf("Unicode Omega: \u03A9\n");

    // Printing a Unicode character using \UXXXXXXXX
    // Example: Unicode for '😊' is U+1F60A
    printf("Unicode Smiley: \U0001F60A\n");

    return 0;
}
