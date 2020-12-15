#include "level.h"

void gameplay(t_lvl **level, int map_size_y, int map_size_x) {
    initscr();
    noecho();

    int y_max = map_size_y;
    int x_max = map_size_x;

    int y = (*level) -> player_pos[0];
    int x = (*level) -> player_pos[1];

    (*level) -> map[y][x] = ' ';    // hide start position

    int btn_counter = 0;

    for(int i = 0; (*level) -> btn_pos[i]; i++) {
        btn_counter++;
    }

    WINDOW *game_window = newwin(y_max, x_max, 2, 5);
    keypad(game_window, TRUE);

    for( ;; ) {
        for(int i=0; i<map_size_y; i++) {
            for(int j=0; j<map_size_x; j++) {
                wmove(game_window, i, j);
                waddch(game_window, (*level) -> map[i][j]);
            }
        }

//        for (int i=0; (*level) -> btn_pos[i]; i++) {
//            wmove(game_window, (*level) -> btn_pos[i][0], (*level) -> btn_pos[i][1]);
//            waddch(game_window, MX_BTN_CHAR);
//        }
        
        wmove(game_window, y, x);
        waddch(game_window, MX_PLAYER_CHAR);

        int ch = wgetch(game_window);
        if (ch == KEY_DOWN) {
            if(y+1 < y_max) {
                if ((*level) -> map[y+1][x] == ' ' || (*level) -> map[y+1][x] == MX_BTN_CHAR) {
                    y++;
                }

                else if((*level) -> map[y+1][x] == MX_BOX_CHAR) {
                    if((*level) -> map[y+2][x] == ' ' && y+2 < y_max) {
                        (*level) -> map[y+2][x] = MX_BOX_CHAR;
                        (*level) -> map[y+1][x] = ' ';
                        y++;
                    }
                    else if((*level) -> map[y+2][x] == MX_BTN_CHAR && y+2 < y_max) {
                        (*level) -> map[y+2][x] = 'x';
                        (*level) -> map[y+1][x] = ' ';
                        btn_counter--;
                        y++;
                    }
                }
                // else if((*level) -> map[y+1][x] == MX_BOX_CHAR) {
                //     if(((*level) -> map[y+2][x] == ' ' || (*level) -> map[y+2][x] == MX_BTN_CHAR) && y+2 < y_max) {
                //         (*level) -> map[y+2][x] = MX_BOX_CHAR;
                //         (*level) -> map[y+1][x] = ' ';
                //         y++;
                //     }
                // }
            }
        }
        if (ch == KEY_UP){
            if(y > 0) {
                if ((*level) -> map[y-1][x] == ' ' || (*level) -> map[y-1][x] == MX_BTN_CHAR) {
                    y--;
                }
                else if((*level) -> map[y-1][x] == MX_BOX_CHAR) {
                    if((*level) -> map[y-2][x] == ' ' && y-2 > 0) {
                        (*level) -> map[y-2][x] = MX_BOX_CHAR;
                        (*level) -> map[y-1][x] = ' ';
                        y--;
                    }
                    else if((*level) -> map[y-2][x] == MX_BTN_CHAR && y-2 > 0) {
                        (*level) -> map[y-2][x] = 'x';
                        (*level) -> map[y-1][x] = ' ';
                        btn_counter--;
                        y--;
                    }
                }
            }
        }
        if (ch == KEY_LEFT) {
            if(x > 0) {
                if ((*level) -> map[y][x-1] == ' ' || (*level) -> map[y][x-1] == MX_BTN_CHAR) {
                    x--;
                }
                else if((*level) -> map[y][x-1] == MX_BOX_CHAR) {
                    if((*level) -> map[y][x-2] == ' ' && x-2 > 0) {
                        (*level) -> map[y][x-2] = MX_BOX_CHAR;
                        (*level) -> map[y][x-1] = ' ';
                        x--;
                    }
                    else if((*level) -> map[y][x-2] == MX_BTN_CHAR && x-2 > 0) {
                        (*level) -> map[y][x-2] = 'x';
                        (*level) -> map[y][x-1] = ' ';
                        btn_counter--;
                        x--;
                    }
                }
            }
        }
        if (ch == KEY_RIGHT) {
            if(x+1 < x_max) {
                if ((*level) -> map[y][x+1] == ' ' || (*level) -> map[y][x+1] == MX_BTN_CHAR) {
                    x++;
                }
                else if((*level) -> map[y][x+1] == MX_BOX_CHAR) {
                    if((*level) -> map[y][x+2] == ' ' && x+2 < x_max) {
                        (*level) -> map[y][x+2] = MX_BOX_CHAR;
                        (*level) -> map[y][x+1] = ' ';
                        x++;
                    }
                    else if((*level) -> map[y][x+2] == MX_BTN_CHAR && x+2 < x_max) {
                        (*level) -> map[y][x+2] = 'x';
                        (*level) -> map[y][x+1] = ' ';
                        btn_counter--;
                        x++;
                    }
                }
            }
        }
        if (ch == 'q') {
            break;
        }
        if (btn_counter == 0) {
            break;
        }
    }
    delwin(game_window);
}
