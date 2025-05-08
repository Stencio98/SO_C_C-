#include "TUI_library.h"
#include <string.h>

#define WIDTH  40
#define HEIGHT 10

#define FILE_ARRAY 100
//function to handle login
int login() {
    WINDOW *win;
    int startx, starty;
    char input[80];
    char pass[80] = "password";

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    startx = (COLS - WIDTH) / 2;
    starty = (LINES - HEIGHT) / 2;

    win = newwin(HEIGHT, WIDTH, starty, startx);
    box(win, 0, 0);
    mvwprintw(win, 0, (WIDTH - strlen("  LOGIN  ")) / 2, "  LOGIN  ");
    mvwprintw(win, 2, (WIDTH - strlen("Password:"))/2, "Password:");
    wrefresh(win);

    mvwgetnstr(win, 4, 2, input, 79);

    if (strcmp(input, pass) == 0) {
        werase(win);
        box(win, 0, 0);
        mvwprintw(win, 4, (WIDTH - strlen("login done")) / 2, "login done");
        mvwprintw(win, 6, (WIDTH - strlen("press a key to continue")) / 2, "press a key to continue");
        wrefresh(win);
        
        wgetch(win);
        delwin(win);
        endwin();
        return 1;
    } else {
        werase(win);
        box(win, 0, 0);
        mvwprintw(win, 4, (WIDTH - strlen("login fallito")) / 2, "login fallito");
		mvwprintw(win, 6, (WIDTH - strlen("press a key to continue")) / 2, "press a key to continue");
        wrefresh(win);
        
        wgetch(win);
        delwin(win);
        endwin();
        return 0;
    }
}







//return the number of the operation selected
int choose_operation(){
	
    WINDOW *menu_win;
    int startx, starty, width, height;
    int choice = 0;
    int highlight = 1; // opzione evidenziata

    height = 20; // altezza della finestra del menu
    width = 80;  // larghezza della finestra del menu
    starty = (LINES - height) / 2;
    startx = (COLS - width) / 2;

    // crea la finestra del menu
    menu_win = newwin(height, width, starty, startx);
    keypad(menu_win, TRUE);
    box(menu_win, 0, 0);
    wrefresh(menu_win);

    // Opzioni del menu

    //int n_choices = sizeof(commands) / sizeof(commands[0]);

    while(1) {
        // Disegna le scelte
        for (int i = 0; i < num_lines; ++i) {
            if (i == highlight - 1)
                wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, i + 2, 2, "%s", commands[i]);
            wattroff(menu_win, A_REVERSE);
        }
        wrefresh(menu_win);

        int c = wgetch(menu_win);
        switch(c) {
            case KEY_UP:
                if (highlight == 1)
                    highlight = num_lines;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if (highlight == num_lines)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case 10: // ENTER
                choice = highlight;
                break;
            default:
                break;
        }

        if (choice != 0) {
            break; // uscire dal ciclo quando una scelta è confermata
        }
    }

    // Gestione delle scelte
    switch (choice) {
        case 1:
            // Invoca funzione aggiungi elemento
            // esempio: add_element();
            break;
        case 2:
            // Invoca funzione visualizza elementi
            // esempio: display_elements();
            break;
        case 3:
            // Esci dal programma
            delwin(menu_win);
            endwin();
            // terminare il programma o tornare
            return -1;
    }

    // Pulizia
    delwin(menu_win);
    // Dopo aver gestito l’operazione, puoi continuare o ricominciare
    return 0;
}




char **leggiFileInMatrice(const char *nomeFile, int *numeroRighe) {
    FILE *file = fopen(nomeFile, "r");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        *numeroRighe = 0;
        return NULL;
    }

    // Prima passata: conta quante righe ci sono
    int count = 0;
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        count++;
    }

    // Reset del puntatore del file all'inizio
    rewind(file);

    // Alloca la memoria per la matrice (array di puntatori a stringhe)
    char **matrice = malloc(sizeof(char *) * count);
    if (matrice == NULL) {
        perror("Errore di allocazione della memoria");
        fclose(file);
        *numeroRighe = 0;
        return NULL;
    }

    // Legge le righe e le memorizza
    int i = 0;
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        // Rimuove il carattere di newline alla fine della riga, se presente
        buffer[strcspn(buffer, "\n")] = '\0';

        // Alloca memoria per la riga
        matrice[i] = malloc(strlen(buffer) + 1);
        if (matrice[i] == NULL) {
            perror("Errore di allocazione della memoria");
            // Liberare le righe già allocate prima di uscire
            for (int j = 0; j < i; j++) {
                free(matrice[j]);
            }
            free(matrice);
            fclose(file);
            *numeroRighe = 0;
            return NULL;
        }
        strcpy(matrice[i], buffer);
        i++;
    }

    fclose(file);
    *numeroRighe = count;
    return matrice;
}























