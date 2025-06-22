#include <stdio.h>
int main (){
	char buffer[256]; // cella 255 terminazione stringa --> la stringa può essere lunga da 0 a 254 al massimo
	printf("Insert String: \n");
	fgets(buffer, 256, stdin);
	printf("check Str: %s\n", buffer);
	
	char *p;
	int i = 0;
	p = buffer;
	while(*p != '\0'){
		i++;
		p++;
	}
	printf("i: %d\n", i);
	
	char buffer_reverse[i];
	p = buffer_reverse;
	while(i > -1){
		*p = buffer[i-1]; // buffer[i] == '\0'
		//printf("*p = buffer[%d]: %c\n", i, *p); --> indagare (?)
		i--;
		p++;
	}
	*p = '\0';
	printf("Str Reverse: %s\n", buffer_reverse);
}
