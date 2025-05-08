#include <ncurses.h>
#include <string.h>
#include <unistd.h>

#define WIDTH  40
#define HEIGHT 10

int main() {
    WINDOW *win;
    int startx, starty;
    char input[80];

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    startx = (COLS - WIDTH) / 2;
    starty = (LINES - HEIGHT) / 2;

    win = newwin(HEIGHT, WIDTH, starty, startx);
    box(win, 0, 0);

    mvwprintw(win, 0, (WIDTH - strlen("  LOGIN  ")) / 2, "  LOGIN  ");
    mvwprintw(win, 2, (WIDTH - strlen("Password:")) / 2, "Password:");
    wrefresh(win);

    mvwgetnstr(win, 4, 2, input, 79);

    char pass[80] = "password";
    if (strcmp(input, pass) == 0) {
        // Password corretta → Menù opzioni
        char *options[] = { "Opzione 1", "Opzione 2", "Esci" };
        int num_options = sizeof(options) / sizeof(options[0]);
        int selected = 0;
        int ch;

        keypad(win, TRUE);
        curs_set(0); // nascondi il cursore

        while (1) {
            werase(win);
            box(win, 0, 0);
            mvwprintw(win, 0, (WIDTH - strlen("  MENU  ")) / 2, "  MENU  ");

            for (int i = 0; i < num_options; i++) {
                if (i == selected)
                    wattron(win, A_REVERSE);

                mvwprintw(win, 2 + i, 2, "%s", options[i]);

                if (i == selected)
                    wattroff(win, A_REVERSE);
            }

            wrefresh(win);

            ch = wgetch(win);
            switch (ch) {
                case KEY_UP:
                    selected = (selected == 0) ? num_options - 1 : selected - 1;
                    break;
                case KEY_DOWN:
                    selected = (selected == num_options - 1) ? 0 : selected + 1;
                    break;
                case 10: // Invio
                    if (selected == num_options - 1) {
                        delwin(win);
                        endwin();
                        return 0;
                    } else {
                        werase(win);
                        box(win, 0, 0);
                        mvwprintw(win, HEIGHT / 2, (WIDTH - strlen("Hai scelto un'opzione")) / 2, "Hai scelto un'opzione");
                        wrefresh(win);
                        sleep(1);
                    }
                    break;
            }
        }
    } else {
        werase(win);
        box(win, 0, 0);
        mvwprintw(win, 6, (WIDTH - strlen("login fallito")) / 2, "login fallito");
        wrefresh(win);
        wgetch(win);
        delwin(win);
        endwin();
    }

    delwin(win);
    endwin();
    return 0;
}
