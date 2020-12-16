#pragma once

#include "level.h"

// void gameplay (t_lvl *level);
void gameplay(t_lvl **level, int map_size_y, int map_size_x);
bool check_btn(t_lvl **level, int y, int x);
bool check_box(t_lvl **level, int y, int x);
void move_box(t_lvl **level, int y_now, int x_now, int y_step, int x_step);
void hide_char(t_lvl **level, char c, int map_size_y, int map_size_x);
