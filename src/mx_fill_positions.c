#include "level.h"

static int get_box_count(char *filename) {
    int fd;
    char ch;
    int count = 0;

    if ((fd = open(filename, O_RDONLY)) != -1) {
        for (count = 0; read(fd, &ch, 1); count += ch == MX_BOX_CHAR ? 1 : 0);
        close(fd);
    }
    return count;
}

static void parse_map(int fd, char ch, int pos_count, t_lvl **lvl) {
    int box_idx = 0;
    int btn_idx = 0;
    int x;
    int y;

    for (x = 0, y = 0; read(fd, &ch, 1); x++, y += ch == '\n' ? !(x = 0) : 0) {
        if (ch == MX_BOX_CHAR && box_idx < pos_count) {
            (*lvl)->box_pos[box_idx] = malloc(sizeof(int) * 2);
            (*lvl)->box_pos[box_idx][MX_Y] = y;
            (*lvl)->box_pos[box_idx][MX_X] = x;
            box_idx++;
        } else if (ch == MX_BTN_CHAR) {
            (*lvl)->btn_pos[btn_idx] = malloc(sizeof(int) * 2);
            (*lvl)->btn_pos[btn_idx][MX_Y] = y;
            (*lvl)->btn_pos[btn_idx][MX_X] = x;
            // printw("\n\n%s BTN:\n", ((*lvl)->name));
            // printw("y:%d x:%d\n", (*lvl)->btn_pos[btn_idx][MX_Y], (*lvl)->btn_pos[btn_idx][MX_X]);
            btn_idx++;
        } else if (ch == MX_PLAYER_CHAR) {
            (*lvl)->player_pos[MX_Y] = y;
            (*lvl)->player_pos[MX_X] = x;
        }
    }
    (*lvl)->box_pos[box_idx] = NULL;
    (*lvl)->btn_pos[btn_idx] = NULL;
    // printw("\n\n%s:\n", ((*lvl)->name));
    // mx_print_lvl(*lvl);
}

void mx_fill_positions(char *filename, t_lvl **lvl) {
    int fd;
    char ch;
    int box_count = get_box_count(filename);
    int i;

    if ((fd = open(filename, O_RDONLY))!= -1) {
        (*lvl)->box_pos = malloc(sizeof(int) * box_count * 8);
        (*lvl)->btn_pos = malloc(sizeof(int) * box_count * 8);
        for (i = 0; read(fd, &ch, 1) && i < 3; i += ch == '\n' ? 1 : 0);
        parse_map(fd, ch, box_count, lvl);
        close(fd);
    }
    else {
        (*lvl)->box_pos = NULL;
        (*lvl)->btn_pos = NULL;
    }
}
