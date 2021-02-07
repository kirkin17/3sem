#include <ncurses.h>
#include "Generator.h"
#include <locale.h>
#include <string>

#define SIZE 9

void menu()
{
    /*std::string title =
        " ▄▄▄▄  ▄    ▄ ▄▄▄▄    ▄▄▄▄  ▄    ▄ ▄    ▄\n\
        █▀   ▀ █    █ █   ▀▄ ▄▀  ▀▄ █  ▄▀  █    █\n\
        ▀█▄▄▄  █    █ █    █ █    █ █▄█    █    █\n\
            ▀█ █    █ █    █ █    █ █  █▄  █    █\n\
        ▀▄▄▄█▀ ▀▄▄▄▄▀ █▄▄▄▀   █▄▄█  █   ▀▄ ▀▄▄▄▄▀\n";*/
    
    curs_set(0);
    keypad(stdscr, true);
    //printw("%s",title);
    printw("\n\n");
    printw(" PLAY\n");
    printw(" About\n");
    printw(" Exit");
}

int main()
{
    setlocale(LC_ALL, "");  
    initscr();            
    menu();
    Generator gen(0);
    auto grid = gen.getGrid();
    printw("%", grid.size());
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            printw("&d ", grid[i][j]);
        }
    }
    getch();                   
    endwin();                 
}