#include <stdio.h>

int main(){
	int consonants = 0;
	int volwels = 0;
	int numbers = 0;
	
	char buffer[256];
	printf("Insert String: \n");
	fgets(buffer, 256, stdin);
	
	char *p;
	p = buffer;
	while(*p != '\0'){
		if((*p >= 65 && *p <= 90) || (*p >= 97 && *p <= 122)){
			if(*p == 'a'||*p == 'e'||*p == 'i'|| *p == 'o' || *p == 'u' || 
			*p == 'A'||*p == 'E'||*p == 'I'|| *p == 'O' || *p == 'U'){volwels++;}
			else {consonants++;}
		}
		if(*p >= 48 && *p <= 57){numbers++;}
		p++;
	}
	printf("consonants: %d\n", consonants);
	printf("volwels: %d\n", volwels);
	printf("numbers: %d\n", numbers);
}
