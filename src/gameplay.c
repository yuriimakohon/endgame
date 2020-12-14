#include "../inc/gameplay.h"
#include <ncurses.h>
#include "../inc/level.h"

void gameplay() {
    initscr();
    noecho();

    int x = 5;
    int y = 5;

    int x_max = 26;
    int y_max = 8;

//    int x_start = 5;
//    int y_start = 5;

    WINDOW *game_window = newwin(y_max, x_max, 5, 5);
    keypad(game_window, TRUE);

    for( ;; ) {
        curs_set(0);
        wmove(game_window, y,x);
        waddch(game_window, 'X');
        int ch = wgetch(game_window);
        if (ch == KEY_DOWN && y+1 < y_max) {
            y++;
        }
        if (ch == KEY_UP && y-1 > 0) {
            y--;
        }
        if (ch == KEY_LEFT && x-1 > 0) {
            x--;
        }
        if (ch == KEY_RIGHT && x+1 < x_max) {
            x++;
        }
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

//void 




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
