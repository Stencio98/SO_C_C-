#include "TUI_library.h"
#include <string.h>

#define WIDTH  40
#define HEIGHT 10

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
        mvwprintw(win, 6, (WIDTH - strlen("login fallito")) / 2, "login fallito");
        wrefresh(win);
        wgetch(win);
        delwin(win);
        endwin();
        return 0;
    }
}

int choose_operation(){

}
