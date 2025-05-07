#include <stdio.h>
#include <string.h>  /* per strerror */
#include <errno.h>   /* per errno */
#include <ctype.h>   /* per islower */

/*
 * Programma che  legge in  ingresso il file  passato in  ingresso con
 * argv[1] e scrive in uscita il file argv[2] in cui ogni carattere di
 * argv[1] viene modificato
 */
int main(int argc, char * argv[])
{
	FILE *f_i, *f_o;
	int c;
	
	/* Opening the file to be read */
	if ((f_i = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Errore in apertura \"%s\".\n",	argv[1]);
		return -1;
	}

	/* Opening the file to be written */
	if ((f_o = fopen(argv[2], "w")) == NULL) {
		fprintf(stderr, "Errore in apertura \"%s\".\n", argv[2]);
		return -1;
	}

	/* Looping reading and writing */
	while ((c = fgetc(f_i)) != EOF) {
		/* minuscolo in maiuscolo */
		c = islower(c) ? ~0x20 & c : c;

		fputc(c, f_o);
	}
	printf("Last position of file %lu\n", ftell(f_i));
	
	fclose(f_o);
	fclose(f_i);
}
