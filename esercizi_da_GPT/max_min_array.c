#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(){
	int a[5];
	int b[5];
	printf("insert 5 numbers (separated from \\n):\n");
	int i = 0;
	while(i < 5){
		scanf("%d",&a[i]);
		i++;
	}
	
	printf("Random array b:\n");
	i = 0;
	srand(time(NULL));
	while(i < 5){
		b[i] = rand() % 11;
		printf("b[%d]: %d\n", i, b[i]);	
		i++;
	}
	
	i = 0;
	int a_max, a_min, b_max, b_min;
	b_max = b_min = b[0];
	a_max = a_min = a[0];
	while(i < 5){
		if(a[i] < a_min){a_min = a[i];}
		if(a[i] > a_max){a_max = a[i];}
		
		if(b[i] < b_min){b_min = b[i];}
		if(b[i] > b_max){b_max = b[i];}
		
		i++;
	}
	
	printf("a_max: %d\n", a_max);
	printf("a_min: %d\n", a_min);
	printf("b_max: %d\n", b_max);
	printf("b_min: %d\n", b_min);
	return 0;
}
