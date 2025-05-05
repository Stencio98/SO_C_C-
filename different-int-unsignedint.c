#include <stdio.h>

int main() {

    printf("Hexadecimal: %X\n", (int)(-10));
    printf("F --> 1111\n");
    printf("6 --> 0110\n");
    printf("1111|1111|1111|1111|1111|1111|1111|0110");
    printf("\n\n");
    printf("Signed decimal: %d\n", (int)(-10));
    printf("\n\n");
    printf("Unsigned decimal: %u\n", (unsigned int)(-10));
    return 0;
}
