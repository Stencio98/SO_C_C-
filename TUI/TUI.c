#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <string.h>

#define WIDTH  40
#define HEIGHT 10
#define ZZZZZZ

int main() {
    WINDOW *win; // pointer to a WINDOW --> WINDOW is an ncurses object
    int startx, starty; //typically will store x and y coordinates, for example, where to position windows or text
    char input[80];

    // Inizializza ncurses
    initscr(); // inizialize TUI
    cbreak(); // no buffer keys
    //noecho(); // no print characters written
    keypad(stdscr, TRUE);

    // Calcola posizione centrale della finestra
    startx = (COLS - WIDTH) / 2;
    starty = (LINES - HEIGHT) / 2;

    // Crea una nuova finestra
    win = newwin(HEIGHT, WIDTH, starty, startx);
    box(win, 0, 0); // disegna bordo

    // Titolo
    mvwprintw(win, 0, (WIDTH - strlen("  LOGIN  ")) / 2, "  LOGIN  ");

    // Istruzioni
    //mvwprintw(win, 2, 2, "Password:");
    mvwprintw(win, 2, (WIDTH - strlen("Password:"))/2, "Password:");
    wrefresh(win);

    // Posiziona il cursore per l'input
    mvwgetnstr(win, 4, 2, input, 79);

#ifndef ZZZZZZ
    // Pulisci la finestra e mostra il saluto
    werase(win);
    box(win, 0, 0);
    mvwprintw(win, 0, (WIDTH - strlen("  RISULTATO  ")) / 2, "  RISULTATO  ");
    mvwprintw(win, 3, (WIDTH - strlen(input)) / 2, "Ciao, %s!", input);
    mvwprintw(win, 6, (WIDTH - strlen("Premi un tasto per uscire")) / 2, "Premi un tasto per uscire");
    wrefresh(win);
    wgetch(win); // aspetta un tasto

    // Termina ncurses
    delwin(win);
    endwin();
#endif

    char pass[80] = "password";
    if (strcmp(input, pass) == 0) {
        werase(win);
        box(win, 0, 0);
        mvwprintw(win, 6, (WIDTH - strlen("quanto tempo bro")) / 2, "quanto tempo bro");
        wrefresh(win);
    } else {
        werase(win);
        box(win, 0, 0);
        mvwprintw(win, 6, (WIDTH - strlen("login fallito")) / 2, "login fallito");
        wrefresh(win);
        wgetch(win); // aspetta un tasto
        delwin(win);
        endwin();
    }
    wgetch(win); // aspetta un tasto
    delwin(win);
    endwin();

    return 0;
}
