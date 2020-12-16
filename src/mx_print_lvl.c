#include "level.h"

void mx_print_lvl(t_lvl *lvl) {     // TODO: Delete this file
    printw("%s\n", lvl->name);
    printw("%d : %d\n", lvl->map_w, lvl->map_h);
    printw("BOXES:\n");
    for (int i = 0; lvl->box_pos[i]; i++) {
        printw("X%d: y:%d x:%d\n", i, lvl->box_pos[i][MX_Y], lvl->box_pos[i][MX_X]);
    }
    printw("BUTTONS:\n");
    for (int i = 0; lvl->btn_pos[i]; i++) {
        printw("O%d: y:%d x:%d\n", i, lvl->btn_pos[i][MX_Y], lvl->btn_pos[i][MX_X]);
    }
    for (int i = 0; lvl->map[i]; i++)
        printw("%s\n", lvl->map[i]);
    printw("\n\n");
}
