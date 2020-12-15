// #include "level.h"
#include "gameplay.h"

// void mx_init_ncurses() {
//     initscr();
//     noecho();
//     set_cursor(0);
// }

static void test(void) {
    t_lvl **lvls = mx_create_lvls();
    mx_delete_lvls(&lvls);
}


/*
int main () {

    t_lvl *level = mx_create_lvl("resource/level/lvl_1");
    gameplay(&level, 8, 26);
}
*/

int main(void) {
    // mx_init_ncurses();
    // test();
    // system("leaks -q endgame");
//    t_lvl *level = mx_create_lvl("resource/level/lvl_1");
//    gameplay(&level, 8, 26);
}
