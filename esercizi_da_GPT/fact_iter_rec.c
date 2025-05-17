#include <stdio.h>

int fact_iter(int n){
	if(n < 0){printf("n < 0 --> now n > 0\n"); n = n * -1;}
	int fact = 1;
	if(n == 0){printf("n == 0\n"); return 1;}
	while(n != 0){
			fact = fact * n;
			n--;
	}
	return fact;
}

int fact_rec(int n){
		if(n < 0){printf("n < 0 --> now n > 0\n"); n = n * -1;}
		if(n == 0){printf("n == 0"); return 1;}
		return n * fact_rec(n - 1);
	}

int main(){
	printf("fact_iter(3): %d\n\n", fact_iter(3));
	printf("fact_iter(-3): %d\n\n", fact_iter(-3));
	printf("fact_iter(0): %d\n\n", fact_iter(0));
	
	printf("fact_rec(3): %d\n\n", fact_rec(3));
	printf("fact_rec(-3): %d\n\n", fact_rec(-3));
	printf("fact_rec(0): %d\n\n", fact_rec(0));
	
}
