#include "level.h"

void mx_init_ncurses() {
    initscr();
    noecho();
    curs_set(0);
}

static void test(void) {
    t_lvl **lvls = mx_create_lvls();
    mx_show_main_menu(lvls);
    mx_delete_lvls(&lvls);
}

int main(void) {
    mx_init_ncurses();
    test();
    endwin();
    system("leaks -q endgame");
}
