#include "../inc/gameplay.h"
#include <ncurses.h>
#include "../inc/level.h"

void gameplay() {
    initscr();
    noecho();

    

    int x_max = 26;
    int y_max = 8;

//    int wall_x = 6;
//    int wall_y = 6;

    int x_start = 19;
    int y_start = 5;

    int x = x_start;
    int y = y_start;

    char map[8][26] = {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#',' ','0','#','#',' ',' ','X',' ',' ',' ','0','#','#',' ',' ',' ','#',' ',' ',' ','#','#','#','#','#'},
        {'#',' ','X','#','#',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ','#',' ',' ',' ',' ','0',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
    };    

    WINDOW *game_window = newwin(y_max, x_max, 2, 5);
    keypad(game_window, TRUE);
    curs_set(0);


/*
    for(int i=0; i<8; i++) {
        for(int j=0; j<26; j++) {
            wmove(game_window, i, j);
            waddch(game_window, map[i][j]);
        }
    }
*/

    for( ;; ) {
        for(int i=0; i<8; i++) {
            for(int j=0; j<26; j++) {
                wmove(game_window, i, j);
                waddch(game_window, map[i][j]);
            }
        }
        wmove(game_window, y,x);
        waddch(game_window, '@');

        int ch = wgetch(game_window);
        if (ch == KEY_DOWN) {
            if(y+1 < y_max) {
                if (map[y+1][x] != '#') {
                    y++;
                }
            }
        }
        if (ch == KEY_UP){
            if(y > 0) {
                if (map[y-1][x] != '#') {
                    y--;
                }
            }
        }
        if (ch == KEY_LEFT) {
            if(x > 0) {
                if (map[y][x-1] != '#') {
                    x--;
                }
            }
        }
        if (ch == KEY_RIGHT) {
            if(x+1 < x_max) {
                if (map[y][x+1] != '#') {
                    x++;
                }
            }
        }
/*
        int ch = wgetch(game_window);
        if (ch == KEY_DOWN) {
            if(y+1 < y_max) {
                if (!(y+1 == wall_y && x == wall_x)) {
                    y++;
                }
            }
        }
        
        if (ch == KEY_UP){
            if(y > 0) {
                if (!(y-1 == wall_y && x == wall_x)) {
                    y--;
                }
            }
        }
        
        if (ch == KEY_LEFT) {
            if(x > 0) {
                if (!(y == wall_y && x-1 == wall_x)) {
                    x--;
                }
            }
        }
        
        if (ch == KEY_RIGHT) {
            if(x+1 < x_max) {
                if (!(y == wall_y && x+1 == wall_x)) {
                    x++;
                }
            }
        }
*/

        if (ch == 'q') {
            break;
        }
        
        wclear(game_window);
        wrefresh(game_window);
    }
    delwin(game_window);
    endwin();
}



int main () {
    gameplay();
}

void print_map() {

}




/*
// void gameplay (t_lvl *level) {
void gameplay() {

    int x = 6;
    int y = 6;

    initscr();
//    curs_set(0);
//    refresh();
    
//    start_color();
//    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);

    WINDOW *game_window = newwin(8, 26, 5, 5);
    keypad(game_window, TRUE);
//    box(game_window, 1, 2);

//    wattron(game_window, COLOR_PAIR(1));
//    wmove(game_window, 6, 6);
//    waddch(game_window, 'X');

 //   noecho();
//    wrefresh(game_window);
    
    for ( ;; ) {
        wmove(game_window, y, x);
        wprintw(game_window, "X");

        int ch = getch();
        if (ch == KEY_DOWN)  y++;
        if (ch == KEY_UP)    y--;
        if (ch == KEY_LEFT)  x--;
        if (ch == KEY_RIGHT) x++;
        wclear(game_window);
        wrefresh(game_window);
        noecho();
    }
    
    

    delwin(game_window);
    endwin();
}

int main() {
    gameplay();
}
*/
