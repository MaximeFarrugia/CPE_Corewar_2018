/*
** EPITECH PROJECT, 2019
** menu
** File description:
** menu
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <ncurses.h>
#include <time.h>

int print_all_random(vm_t *ft, int *count, int tab, int y)
{
    int x = 0;
    int x_left = COLS / 2;
    int colors = 0;
    static int turn = 0;

    colors = rand() % 7;
    x = turn == 0 ? rand() % COLS / 2 : rand() % (COLS - x_left) + x_left;
    if (*count > 5000) {
        usleep(1000);
        mvprintw(y, x, "%s", "  ");
    }
    else {
        usleep(1000);
        attron(COLOR_PAIR(colors));
        mvprintw(y, x, "%s", ft->bytes[tab]);
        attroff(COLOR_PAIR(colors));
    }
    *count = *count > 20000 ? 0 : *count;
    turn = turn == 0 ? 1 : 0;
    return (0);
}

int print_menu(vm_t *ft)
{
    int c = 0;
    int turn = 0;
    int tab = 0;
    int y = 0;

    while (c != ' ' && c != 'q') {
        tab = rand() % my_strlen_tab(ft->bytes);
        y = rand() % LINES;
        print_all_random(ft, &turn, tab, y);
        refresh();
        c = getch();
        turn++;
        display_title();
        display_button();
        refresh();
    }
    if (c == 'q')
        return (84);
    return (0);
}

int menu(vm_t *ft)
{
    ft->bytes = NULL;
    get_bytes(ft);
    srand(time(NULL));
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
    init_all_pair();
    if (print_menu(ft) == 84)
        return (free_array(ft->bytes) | endwin() | 42);
    free_array(ft->bytes);
    return (0);
}