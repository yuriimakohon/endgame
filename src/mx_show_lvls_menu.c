#include "level.h"

static void draw_lvls(t_lvl **lvls, WINDOW *w, int count, int current) {
    char *name = NULL;
    int x_pos = 0;
    int y_pos = 0;

    for (int i = 0; i < count; i++) {
        name = lvls[i]->name;
        x_pos = getmaxx(w) / 2 - strlen(name) / 2;
        y_pos = (getmaxy(w) / (count + 1)) * (1 + i);
        if (i == current) {
            wattron(w, A_STANDOUT);
            mvwprintw(w, y_pos, x_pos, name);
            wattroff(w, A_STANDOUT);
        }
        else
            mvwprintw(w, y_pos, x_pos, name);
    }
    box(w, 0, 0);
    wrefresh(w);
}

static void choose_lvl(WINDOW *w, t_lvl **lvls, int count) {
    int choiсe = 0;
    int ch;

    draw_lvls(lvls, w, count, choiсe);
    while ((ch = wgetch(w))) {
        int steps = 0;

        if (ch == KEY_UP) {
            choiсe--;
            choiсe = choiсe < 0 ? count - 1 : choiсe;
        }
        else if (ch == KEY_DOWN) {
            choiсe++;
            choiсe = choiсe >= count ? 0 : choiсe;
        }
        else if (ch == 10) {
            while ((steps = gameplay(lvls[choiсe]->path)) == -1);
            clear();
            refresh();
            if (steps != -2) {
                printw("POBEDA: %d", steps);
                getch();
            }
        }
        else if (ch == 27)
            return;
        draw_lvls(lvls, w, count, choiсe);
    }
}

void mx_show_lvls_menu(t_lvl **lvls) {
    WINDOW *wlm = NULL; // window levels menu
    int wlm_w = 50;
    int wlm_h = 5;
    int count = 0;

    clear();
    refresh();
    for (; lvls[count]; count++);
    wlm_h *= count;
    wlm = newwin(wlm_h, wlm_w,
                 getmaxy(stdscr) / 2 - wlm_h / 2,
                 getmaxx(stdscr) / 2 - wlm_w / 2);
    keypad(wlm, true);
    wrefresh(wlm);
    choose_lvl(wlm, lvls, count);
    wclear(wlm);
    wrefresh(wlm);
    delwin(wlm);
}
