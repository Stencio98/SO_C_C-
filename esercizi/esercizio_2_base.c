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
			i = len_a;
		}
		i++;
		p++;
	}
	
	
	
	srand(time (NULL));
	printf("same ex but with char\n");
	char b[101];
	int b_len = sizeof(b) / sizeof(b[0]);
	char *pc;
	i = 0;
	perror("0");
	while(i < b_len - 2){
		b[i] = (rand() % (127 + 1 - 33)) + 32; // rand() % 11 --> tra 0..10
		// - 33 --> i primi da 0 a 31 (quindi 32 numeri) non sono stampabili
		// ma anche il carattere 127 DEL non lo è
		// ASCII
		printf("b[%d]: %d --> %c \n", i, b[i], b[i]);
		i++;
	}
	perror("1");
	
	b[100]= '\0';
	pc = b;
	while(*pc != '\0'){
		if (*pc == '!'){
			printf("finded \"!\"\n\a");
		}
		if (*pc == '~'){
			printf("finded \"~\"\n\a");
		}
		pc++;
	}
	printf("i am sorry\n");
	return 0;
}
