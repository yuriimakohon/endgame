#include "level.h"

void gameplay(t_lvl *level) {
    int y_max = level->map_h;
    int x_max = level->map_w;

    int y = level->player_pos[0];
    int x = level->player_pos[1];

    level -> map[y][x] = ' ';    // hide start position

    hide_char(level, MX_BTN_CHAR, y_max, x_max);
    hide_char(level, MX_BOX_CHAR, y_max, x_max);

    int btn_pushed = 0;
    int btn_q = 0;

    for(int i = 0; level -> btn_pos[i]; i++) {
        btn_q++;
    }

    WINDOW *game_window = newwin(y_max, x_max, 2, 5);
    keypad(game_window, TRUE);

    for( ;; ) {
        for(int i=0; i<y_max; i++) {
            for(int j=0; j<y_max; j++) {
                wmove(game_window, i, j);
                waddch(game_window, level -> map[i][j]);
            }
        }
        for (int i=0; level -> btn_pos[i]; i++) {
            wmove(game_window, level -> btn_pos[i][0], level -> btn_pos[i][1]);
            waddch(game_window, MX_BTN_CHAR);
        }
        for (int i=0; level -> box_pos[i]; i++) {
            wmove(game_window, level -> box_pos[i][0], level -> box_pos[i][1]);
            waddch(game_window, MX_BOX_CHAR);
        }
        wmove(game_window, y, x);
        waddch(game_window, MX_PLAYER_CHAR);

        int ch = wgetch(game_window);

        if(ch == KEY_DOWN) {
            if(y+1 < y_max) {
                if (level -> map[y+1][x] != '#') {
                    if (check_box(level, y+1, x)) {
                        if(level -> map[y+2][x] != '#' && !(check_box(level, y+2, x))) {
                            move_box(level,y+1,x,1,0);
                            y++;
                        }
                    }
                    else {
                        y++;
                    }
                }
            }
        }
        if(ch == KEY_UP) {
            if(y-1 > 0) {
                if (level -> map[y-1][x] != '#') {
                    if (check_box(level, y-1, x)) {
                        if(level -> map[y-2][x] != '#' && !(check_box(level, y-2, x))) {
                            move_box(level,y-1,x,-1,0);
                            y--;
                        }
                    }
                    else {
                        y--;
                    }
                }
            }
        }
        if(ch == KEY_RIGHT) {
            if(x+1 < x_max) {
                if (level -> map[y][x+1] != '#') {
                    if (check_box(level, y, x+1)) {
                        if(level -> map[y][x+2] != '#' && !(check_box(level, y, x+2))) {
                            move_box(level,y,x+1,0,1);
                            x++;
                        }
                    }
                    else {
                        x++;
                    }
                }
            }
        }
        if(ch == KEY_LEFT) {
            if(x-1 > 0) {
                if (level -> map[y][x-1] != '#') {
                    if (check_box(level, y, x-1)) {
                        if(level -> map[y][x-2] != '#' && !(check_box(level, y, x-2))) {
                            move_box(level,y,x-1,0,-1);
                            x--;
                        }
                    }
                    else {
                        x--;
                    }
                }
            }
        }
        if (ch == 'q') {
            break;
        }
        btn_pushed = 0;
        for(int i = 0; level -> btn_pos[i]; i++) {
            if(check_box(level, level -> btn_pos[i][0], level -> btn_pos[i][1])) {
                btn_pushed++;
            }
        }

        if (btn_q == btn_pushed) {
             break;
        }
    }
    delwin(game_window);
}

bool check_btn(t_lvl *level, int y, int x) {
    for (int i = 0; level -> btn_pos[i]; i++) {
        if (level -> btn_pos[i][0] == y && level -> btn_pos[i][1] == x) {
            return 1;
        }
    }
    return 0;
}

bool check_box(t_lvl *level, int y, int x) {
    for (int i = 0; level -> box_pos[i]; i++) {
        if (level -> box_pos[i][0] == y && level -> box_pos[i][1] == x) {
            return 1;
        }
    }
    return 0;
}

void move_box(t_lvl *level, int y_now, int x_now, int y_step, int x_step) {
    for (int i = 0; level -> box_pos[i]; i++) {
        if (level -> box_pos[i][0] == y_now && level -> box_pos[i][1] == x_now) {
            level -> box_pos[i][0] = y_now + y_step;
            level -> box_pos[i][1] = x_now + x_step;
            break;
        }
    }
}

void hide_char(t_lvl *level, char c, int map_size_y, int map_size_x) {
    for(int i=0; i<map_size_y; i++) {
        for(int j=0; j<map_size_x; j++) {
            if (level -> map[i][j] == c) {
                level -> map[i][j] = ' ';
            }
        }
    }
}
