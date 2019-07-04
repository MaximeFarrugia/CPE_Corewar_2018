/*
** EPITECH PROJECT, 2019
** init_ncurses
** File description:
** init_ncurses
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"

int init_colors(void)
{
    init_color(COLOR_GRAY, 150, 150, 150);
    init_pair(0, COLOR_GRAY, 0);
    init_pair(1, COLOR_RED, 0);
    init_pair(2, COLOR_BLUE, 0);
    init_pair(3, COLOR_GREEN, 0);
    init_pair(4, COLOR_YELLOW, 0);
    init_pair(5, COLOR_BLACK, COLOR_WHITE);
    init_pair(6, COLOR_MAGENTA, 0);
    init_pair(7, COLOR_WHITE, 0);
    clear();
    return (0);
}

/*
** wins[0] -> board
** wins[1] -> infos
** wins[2] -> player 1
** wins[3] -> player 2
** wins[4] -> player 3
** wins[5] -> player 4
*/
int init_windows(vm_t *vm, int magic)
{
    vm->wins[0] = newwin(66, magic, 0, COLS / 2 - magic / 2 - 1);
    box(vm->wins[0], 0, 0);
    wrefresh(vm->wins[0]);
    vm->wins[1] = newwin(15, 61, 66, COLS / 2 - magic / 2 - 1);
    box(vm->wins[1], 0, 0);
    wrefresh(vm->wins[1]);
    vm->wins[2] = newwin(15, 57, 66, COLS / 2 - magic / 2 - 1 + 61);
    box(vm->wins[2], 0, 0);
    wrefresh(vm->wins[2]);
    vm->wins[3] = newwin(15, 57, 66, COLS / 2 - magic / 2 - 1 + 118);
    box(vm->wins[3], 0, 0);
    wrefresh(vm->wins[3]);
    vm->wins[4] = newwin(15, 57, 66, COLS / 2 - magic / 2 - 1 + 175);
    box(vm->wins[4], 0, 0);
    wrefresh(vm->wins[4]);
    vm->wins[5] = newwin(15, 57, 66, COLS / 2 - magic / 2 - 1 + 232);
    box(vm->wins[5], 0, 0);
    wrefresh(vm->wins[5]);
    return (0);
}

int init_ncurses(vm_t *vm)
{
    if (init_colors() == 84)
        return (endwin() | 84);
    init_windows(vm, (MEM_SIZE / 64) * 2 + (MEM_SIZE / 64 - 1) + 2);
    return (0);
}