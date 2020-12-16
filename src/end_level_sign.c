// #include <ncurses.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

#include "level.h"
void level_complete_sign(int steps) {
    const int width = 50;
    const int height = 25;
    initscr();
    curs_set(0);
    noecho();
    refresh();
    int offsetx = (COLS - width) / 2;
    int offsety = (LINES - height) / 2;
    WINDOW *win = newwin(height, width, offsety, offsetx);
    start_color(); 
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    wbkgd(win, COLOR_PAIR(3));
    color_set(1, NULL);
    char congrats1[] = "CONGRATS!";
    char congrats2[] = "LEVEL COMPLETE!";
    char warn[] = "Press any key";
    char numofsteps[] = "Number of steps: ";

    mvaddstr(12, (COLS - strlen(congrats1)) / 2, congrats1);
    mvaddstr(14, (COLS - strlen(congrats2)) / 2, congrats2);

    color_set(4, NULL);
    mvaddstr(18, (COLS - strlen(numofsteps)) / 2, numofsteps);
    //mvaddstr(20, (COLS - strlen(numofsteps)) / 2, steps);
    mvprintw(20, (COLS - 4) /2 , "%d", steps);
    mvprintw(24, (COLS - strlen(warn)) / 2 , warn);
    color_set(2, NULL);
    // int hg = 22;
    // int wd = 14;

    // for(unsigned int i = 0; i < strlen(warn); i++) {
    //     wmove(win, hg, wd);
    //     waddch(win, warn[i] | A_BLINK | COLOR_PAIR(2));
    //     wd++;
    // }

    box(win, 0, 0);

    refresh();

    getch();
    delwin(win);
    endwin();
}

// int main() {
//     lvl_complete_sign();
// }
