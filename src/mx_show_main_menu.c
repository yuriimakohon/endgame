#include "level.h"

static void draw_logo() {
    int x = (getmaxx(stdscr) - 39) / 2;
    int y = (getmaxy(stdscr) - 32) / 2;

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    attron(COLOR_PAIR(1));

    getmaxy(stdscr);
    mvprintw(y + 0, x, "   ____     __        ___       __     ");
    mvprintw(y + 1, x, "  / __/__  / /_____  / _ )__ __/ /____ ");
    mvprintw(y + 2, x, " _\\ \\/ _ \\/  '_/ _ \\/ _  / // / __/ -_)");
    mvprintw(y + 3, x, "/___/\\___/_/\\_\\\\___/____/\\_, /\\__/\\__/ ");
    mvprintw(y + 4, x, "                        /___/          ");

    attroff(COLOR_PAIR(1));

    refresh();
}

static void draw_options(char **options, WINDOW *w, int current) {
    int x_pos = 0;
    int y_pos = 0;

    for (int i = 0; options[i]; i++) {
        x_pos = (getmaxx(w) - strlen(options[i])) / 2;
        y_pos = (getmaxy(w) / 3) * (1 + i);
        if (i == current) {
            wattron(w, A_STANDOUT);
            mvwprintw(w, y_pos, x_pos, options[i]);
            wattroff(w, A_STANDOUT);
        }
        else
            mvwprintw(w, y_pos, x_pos, options[i]);
    }
    box(w, 0, 0);
    draw_logo();
    wrefresh(w);
}

static void choose_option(t_lvl **lvls, WINDOW *w) {
    char *options[2] = {"Choose level", "Exit"};
    int choise = 0;
    int ch;

    draw_options(options, w, choise);
    while ((ch = wgetch(w))) {
        if (ch == KEY_DOWN || ch == KEY_UP)
            choise = choise == 0 ? 1 : 0;
        else if (ch == 10) {
            if (choise == 0)
                mx_show_lvls_menu(lvls);
            else
                break;
        }
        draw_options(options, w, choise);
    }
}

void mx_show_main_menu(t_lvl **lvls) {
    WINDOW *wmm = NULL;     // window main menu
    int wmm_w = 50;
    int wmm_h = 20;

    wmm = newwin(wmm_h, wmm_w,
                 (getmaxy(stdscr) - wmm_h) / 2,
                 (getmaxx(stdscr) - wmm_w) / 2);
    keypad(wmm, true);
    wrefresh(wmm);
    choose_option(lvls, wmm);
    delwin(wmm);
}
