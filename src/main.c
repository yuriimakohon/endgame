#include "level.h"

void mx_init_ncurses() {
    initscr();
    noecho();
    curs_set(0);
}

static void test(void) {
    t_lvl **lvls = mx_create_lvls();
    mx_print_lvl(lvls[0]);
    getch();
    mx_delete_lvls(&lvls);
}

int main(void) {
    mx_init_ncurses();
    test();
    system("leaks -q endgame");
}
