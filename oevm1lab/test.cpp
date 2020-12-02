#include <termios.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>
#include <ncurses.h> /**********    ИЗМЕНИТЕ ЗДЕСЬ   *****************/

void sig_winch (int signo) {
    struct winsize size;
    ioctl (fileno(stdout), TIOCGWINSZ, (char *) &size);
    resizeterm(size.ws_row, size.ws_col);
    nodelay(stdscr, 1);
    while (wgetch(stdscr)!=ERR);
    nodelay(stdscr, 0);
}
int main (int argc, char ** argv) {
    initscr();
    signal(SIGWINCH,sig_winch);
    keypad(stdscr, 1);
    mousemask(BUTTON1_CLICKED, NULL);
    move(2,2);
    refresh();
    while(wgetch(stdscr)==KEY_MOUSE){
        MEVENT event;
        getmouse(&event);
        move(0,0);
        printw("X = %i, Y = %i\n",event.x,event.y);
        refresh();
        move(event.x,event.y);
    }
    endwin();
    exit(EXIT_SUCCESS);
}