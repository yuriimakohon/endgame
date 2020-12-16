#include "level.h"

void mx_print_lvl(t_lvl *lvl) {     // TODO: Delete this file
    printw("%s\n", lvl->name);
    printw("%d : %d\n", lvl->map_w, lvl->map_h);
    for (int i = 0; lvl->map[i]; i++)
        printw("%s\n", lvl->map[i]);
    printw("\n\n");
}
