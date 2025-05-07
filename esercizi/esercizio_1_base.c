#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
//#define SEGV --> macro
// gcc -D SEGV esercizio_1_base.c
int main(){
    int a[10];
    int i = 0;
    int sum = 0;
    int len_a = sizeof(a) / sizeof(a[0]);

#ifdef SEGV //if macro is defined
    while(1){printf("a[%d]: %d\n", i, a[i]);i++;}
#endif

    while(i < 10){ //is better use while(i < len_a){...}
        printf("a[%d]: %d\n", i, a[i]);
        sum = sum + a[i];
        i++;
    }
    printf("sum: %d\n", sum);
    printf("maybe strange number, why?\n\n\n");



    srand(time (NULL) + getpid());
    i = 0;
    sum = 0;
    while(i < 10){
        a[i] = rand();
        printf("a[%d]: %d\n", i, a[i]);
        sum = sum + a[i];
        i++;
    }
    printf("sum: %d\n", sum);
    printf("maybe strange number, why?\n\n\n");



    i = 0;
    sum = 0;
    while(i < 10){
        a[i] = rand()%11;
        printf("a[%d]: %d\n", i, a[i]);
        sum = sum + a[i];
        i++;
    }
    printf("sum: %d\n", sum);
    printf("finally normal exercise\n\n\n");



    i = 0;
    int *p = a;
    while(i < len_a){
        printf("a[%d]: %d\n", i, *(p + i));
        i++;
    }
    printf("array a has been read with pointer *p\n\n\n");

    return 0;
}
