#include "level.h"

static void print_lvl(t_lvl *lvl) {
    printf("%s\n", lvl->name);
    for (int i = 0; lvl->map[i]; i++) {
        printf("%s\n", lvl->map[i]);
    }
    printf("\n\n");
}

static void test(void) {
    t_lvl **lvls = mx_create_lvls();
    mx_delete_lvls(&lvls);
}

int main(void) {
    test();
    system("leaks -q endgame");
}
