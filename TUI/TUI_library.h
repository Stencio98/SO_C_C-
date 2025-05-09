#ifndef TUI_LIBRARY_H
#define TUI_LIBRARY_H

#include <ncurses.h>

// funzione login, ritorna 1 se successo, 0 se fallito
int login();

// ritorna il numero dell'operazione selezionata
char *choose_operation();

// legge il file con i comandi
char **leggiFileInMatrice();

#endif
