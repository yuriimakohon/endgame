#include "level.h"

static void draw_logo() {
    mvprintw(0, 1, " _____     _       _____     _       \n");
    mvprintw(0, 2, "|   __|___| |_ ___| __  |_ _| |_ ___ \n");
    mvprintw(0, 3, "|__   | . | '_| . | __ -| | |  _| -_|\n");
    mvprintw(0, 4, "|_____|___|_,_|___|_____|_  |_| |___|\n");
    mvprintw(0, 5, "                        |___|        \n");
}

static void draw_options(char **options, WINDOW *w, int current) {
    int x_pos = 0;
    int y_pos = 0;

    for (int i = 0; options[i]; i++) {
        x_pos = getmaxx(w) / 2 - strlen(options[i]) / 2;
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

    draw_logo();
    wmm = newwin(wmm_h, wmm_w,
                 getmaxy(stdscr) / 2 - wmm_h / 2,
                 getmaxx(stdscr) / 2 - wmm_w / 2);
    keypad(wmm, true);
    wrefresh(wmm);
    choose_option(lvls, wmm);
    delwin(wmm);
}
