#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(){

	printf("number research in array:\n");
	int find = 3;
	int a[10];
	int len_a = sizeof(a) / sizeof(a[0]);
	int *p;
	p = a;
	int i = 0;
	srand(time (NULL));
	//scomodo coi puntatori ma fatto per esercizio
	while(i < len_a){
		*p = rand()%10;
		printf("a[%d]: %d\n", i, *p);
		p++;
		i++;
	}
	i = 0;
	p = a;
	while(i < len_a){
		if (*p == find){
			printf("array contains value: %d\n\n\n\n", find);
			return 0;
		}
		i++;
		p++;
	}
	printf("array does not contains %d\n\n\n\n", find);
	
	
	
	
	
	printf("same ex but with char\n");
	char b[100];
	char *pc;
	
	while()
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
