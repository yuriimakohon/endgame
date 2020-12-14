#include "level.h"

static void delete_pos(int ***pos) {
    if (*pos) {
        for (int i = 0; (*pos)[i]; i++) {
            free((*pos)[i]);
            (*pos)[i] = NULL;
        }
        free(*pos);
        *pos = NULL;
    }
}

void mx_delete_lvl(t_lvl **lvl) {
    if ((*lvl)->name)
        mx_strdel(&(*lvl)->name);
    mx_del_strarr(&(*lvl)->map);
    delete_pos(&(*lvl)->box_pos);
    delete_pos(&(*lvl)->btn_pos);
    free(*lvl);
    *lvl = NULL;
}

void mx_delete_lvls(t_lvl ***lvl) {
    if (*lvl) {
        for (int i = 0; (*lvl)[i]; i++)
            mx_delete_lvl(&(*lvl)[i]);
        free(*lvl);
        *lvl = NULL;
    }
}
