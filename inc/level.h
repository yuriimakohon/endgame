#pragma once

#include <stdio.h>  // TODO: Delete
#include <stdlib.h>
#include <string.h>
#include "minilibmx.h"
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <ncurses.h>

#define MX_MAX_LVL_NAME     20
#define MX_LVL_DIR          "resource/level"

#define MX_BOX_CHAR         'X'
#define MX_BTN_CHAR         'O'
#define MX_PLAYER_CHAR      '@'

#define MX_Y                0
#define MX_X                1

typedef struct s_lvl {
    char *name;
    char **map;
    int **box_pos;
    int **btn_pos;
    int player_pos[2];
}              t_lvl;

t_lvl *mx_create_lvl(char *filename);
t_lvl **mx_create_lvls();
void mx_fill_map(int fd, t_lvl *lvl);
void mx_fill_positions(char *filename, t_lvl **lvl);
void mx_delete_lvl(t_lvl **lvl);
void mx_delete_lvls(t_lvl ***lvl);

void mx_print_lvl(t_lvl *lvl);  // TODO: Delete
