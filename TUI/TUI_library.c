#include "TUI_library.h"
#include <string.h>
#include <stdlib.h>


#define WIDTH  40
#define HEIGHT 10

#define MAX_RIGHE 100
#define MAX_LUNGHEZZA 256

int login() {
    WINDOW *win;
    int startx, starty;
    char input[80];
    char pass[80] = "0000";

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


char *choose_operation(){
	
    WINDOW *menu_win;
    int startx, starty, width, height;
    int choice = 0;
    int highlight = 1;

    
    starty = (LINES - HEIGHT) / 2;
    startx = (COLS - WIDTH) / 2;

    menu_win = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(menu_win, TRUE);
    box(menu_win, 0, 0);
    wrefresh(menu_win);
	
	int righe = 0;
    char **commands = leggiFileInMatrice("TUI_operations.txt", &righe);

    while(1) {

        for (int i = 0; i < righe; ++i) {
            if (i == highlight - 1){wattron(menu_win, A_REVERSE);}
            
            mvwprintw(menu_win, i + 2, 2, "%s", commands[i]);
            wattroff(menu_win, A_REVERSE);
        }
        wrefresh(menu_win);


        int c = wgetch(menu_win);
        switch(c) {
            case KEY_UP:
                if (highlight == 1)
                    highlight = righe;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if (highlight == righe)
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
            break;
        }
    }

    delwin(menu_win);
    endwin();
    return commands[highlight];
}

char **leggiFileInMatrice(const char *nomeFile, int *numeroRighe) {
    FILE *file = fopen(nomeFile, "r");
    if (file == NULL) {
        perror("Errore apertura file");
        return NULL;
    }

    // Alloca memoria per le righe
    char **matrice = malloc(MAX_RIGHE * sizeof(char *));
    if (matrice == NULL) {
        perror("Errore allocazione memoria -- leggiFileInMatrice()");
        fclose(file);
        return NULL;
    }

    int count = 0;
    char buffer[MAX_LUNGHEZZA];

    while (fgets(buffer, MAX_LUNGHEZZA, file) != NULL && count < MAX_RIGHE) {
        // Rimuovi il carattere di newline se presente
        buffer[strcspn(buffer, "\n")] = '\0';

        // Alloca memoria per la riga
        matrice[count] = malloc((strlen(buffer) + 1) * sizeof(char));
        if (matrice[count] == NULL) {
            perror("Errore allocazione memoria riga -- leggiFileInMatrice()");
            // Dealloca tutte le righe già lette
            for (int i = 0; i < count; i++) {
                free(matrice[i]);
            }
            free(matrice);
            fclose(file);
            return NULL;
        }

        strcpy(matrice[count], buffer);
        count++;
    }

    fclose(file);
    *numeroRighe = count;
    return matrice;
}

void liberaMatrice(char **matrice, int righe) {
    for (int i = 0; i < righe; i++) {
        free(matrice[i]);
    }
    free(matrice);
}



















































































