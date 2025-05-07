#include <stdio.h>
#define LEN 20

int main() {
    // Declare an array of 10 characters
    char a[10];
    int b[10];

    // Attempting to use a.length --> invalid in C, so comment
    // printf("a.length --> NO in C\n");
    //0 15 size_t
    //-8 7 int
    // Size of the array in bytes
    size_t size_of_a = sizeof(a);
    printf("Size of array a in bytes: %zu\n", size_of_a);
    // Calculate the number of elements in the array
    size_t length_a = sizeof(a) / sizeof(a[0]);
    printf("Number of elements in array a: %zu\n", length_a);

    size_t size_of_b = sizeof(b);
    printf("Size of array a in bytes: %zu\n", size_of_b);
    size_t length_b = sizeof(b) / sizeof(b[0]);
    printf("Number of elements in array a: %zu\n", length_b);

    return 0;
}
