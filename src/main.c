#include "level.h"

void mx_init_ncurses() {
    initscr();
    noecho();
    set_cursor(0);
}

static void test(void) {
    t_lvl **lvls = mx_create_lvls();
    mx_delete_lvls(&lvls);
}

int main(void) {
    mx_init_ncurses();
    test();
    system("leaks -q endgame");
}
