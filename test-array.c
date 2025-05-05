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

    // Optional: Add assertions or checks
    /*
    if (length_a == 10) {
        printf("Test passed: Array length is 10.\n");
    } else {
        printf("Test failed: Array length is not 10.\n");
    }*/

    return 0;
}
