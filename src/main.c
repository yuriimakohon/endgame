#include "level.h"

static void test(void) {
    t_lvl **lvls = mx_create_lvls();
    mx_print_lvl(lvls[0]);
    mx_print_lvl(lvls[1]);
    mx_delete_lvls(&lvls);
}

int main(void) {
    test();
    system("leaks -q endgame");
}
