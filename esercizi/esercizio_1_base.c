#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
//#define SEGV --> macro
// gcc -D SEGV esercizio_1_base.c
int main(){
    int a[10]; // int a[10] = {1} --> all a[i] = 1
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
    printf("maybe strange number, why?\n");
    printf("we have not inizialized the a array, so we read the values that were there before\n\n\n\n");



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
    printf("maybe strange number, why?\n");
	printf("overflow clock mechanism\n\n\n\n");


    i = 0;
    sum = 0;
    while(i < 10){
        a[i] = rand()%11;
        printf("a[%d]: %d\n", i, a[i]);
        sum = sum + a[i];
        i++;
    }
    printf("sum: %d\n", sum);
    printf("finally normal exercise\n\n\n\n");



    i = 0;
    int *p = a;
    while(i < len_a){
        printf("a[%d]: %d\n", i, *(p + i));
        i++;
    }
    printf("array a has been read with pointer *p, pointers work similar to arrays\n\n\n\n");
	
	
	
	printf("string with different ways to print:\n");
	printf("print with printf and %%:\n");
	char str[/*20*/] = "tung tung tung Saur";
	printf("str: %s\n\a", str); // \a allarme(campanella / beep)
	
	printf("str printed with pointers:\n");
	char * pc;
	pc = str;
	printf("str: ");
	while(*pc != '\0'){
		printf("%c", *pc);
		pc++; // like i in array
	}
	printf("\n"); // end string so we print newline


    return 0;
}
