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

int display_title_two(WINDOW *title, int x, int y)
{
    mvwprintw(title, y / 6, x / 2 - 44, "%s", " .d8888b.   .d88888b. 8888888b."
        "  8888888888       888       888        d8888 8888888b.");
    mvwprintw(title, y / 6 + 1, x / 2 - 44, "%s", "d88P  Y88b d88P\" \"Y88b "
        "888   Y88b 888              888   o   888       d88888 888   Y88b");
    mvwprintw(title, y / 6 + 2, x / 2 - 44, "%s", "888    888 888     888 888"
        "    888 888              888  d8b  888      d88P888 888    888");
    mvwprintw(title, y / 6 + 3, x / 2 - 44, "%s", "888        888     888 888"
        "   d88P 8888888          888 d888b 888     d88P 888 888   d88P");
    mvwprintw(title, y / 6 + 4, x / 2 - 44, "%s", "888        888     888"
        " 8888888P\"  888              888d88888b888    d88P  888 8888888P\"");
    mvwprintw(title, y / 6 + 5, x / 2 - 44, "%s", "888    888 888     888 888"
        " T88b   888              88888P Y88888   d88P   888 888 T88b");
    mvwprintw(title, y / 6 + 6, x / 2 - 44, "%s", "Y88b  d88P Y88b. .d88P 888"
        "  T88b  888              8888P   Y8888  d8888888888 888  T88b");
    mvwprintw(title, y / 6 + 7, x / 2 - 44, "%s", " \"Y8888P\"   \"Y88888P\" "
        "888   T88b 8888888888       888P     Y888 d88P     888 888   T88b");
    return (0);
}

int display_title(void)
{
    WINDOW *title = newwin(13, COLS / 2, LINES / 6, COLS / 2 - COLS / 4);
    int x = getmaxx(title);
    int y = getmaxy(title);

    box(title, 0, 0);
    display_title_two(title, x, y);
    wrefresh(title);
    return (0);
}

int display_button(void)
{
    WINDOW *start = newwin(5, COLS / 3, LINES / 2 + LINES / 6,
        COLS / 2 + COLS / 12 - COLS / 4);
    int x = getmaxx(start);
    int y = getmaxy(start);
    static int turn = 0;

    box(start, 0, 0);
    if (turn > 600)
        mvwprintw(start, y / 2, x / 2 - 16,
            "%s", "                                  ");
    else
        mvwprintw(start, y / 2, x / 2 - 16,
            "%s", "Press [SPACE] to launch the game.");
    if (turn > 1200)
        turn = 0;
    wrefresh(start);
    turn++;
    return (0);
}