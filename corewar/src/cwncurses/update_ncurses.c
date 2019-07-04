/*
** EPITECH PROJECT, 2019
** update_ncurses
** File description:
** update_ncurses
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"

int dctxt(WINDOW *win, vector2i_t pos, char *str, int pair)
{
    wattron(win, COLOR_PAIR(pair));
    wattron(win, A_BOLD);
    mvwprintw(win, pos.y, pos.x, str);
    wattroff(win, COLOR_PAIR(pair));
    wattroff(win, A_BOLD);
    return (0);
}

int dcnbr(WINDOW *win, vector2i_t pos, int nbr, int pair)
{
    wattron(win, COLOR_PAIR(pair));
    wattron(win, A_BOLD);
    mvwprintw(win, pos.y, pos.x, "%d", nbr);
    wattroff(win, COLOR_PAIR(pair));
    wattroff(win, A_BOLD);
    return (0);
}

int clean_window(WINDOW *win)
{
    int maxx = 0;
    int maxy = 0;

    getmaxyx(win, maxy, maxx);
    for (int i = 0; i < maxy; ++i) {
        for (int j = 0; j < maxx; ++j)
            mvwprintw(win, i, j, " ");
    }
    return (0);
}

int update_windows(vm_t *vm)
{
    int magic = (MEM_SIZE / 64) * 2 + (MEM_SIZE / 64 - 1) + 2;
    int x = (COLS / 2 - magic / 2 - 1) + magic;

    cw_print_arena(vm);
    update_infos(vm, vm->running ? 20 : 16);
    update_pone(vm);
    update_ptwo(vm);
    update_pthree(vm);
    update_pfour(vm);
    attron(COLOR_PAIR(7));
    attron(A_BOLD);
    mvprintw(LINES / 2 - 3 + 0, x + 1, "W: RUN");
    mvprintw(LINES / 2 - 3 + 2, x + 1, "E: PAUSE");
    mvprintw(LINES / 2 - 3 + 4, x + 1, "S: STEP BY STEP");
    mvprintw(LINES / 2 - 3 + 6, x + 1, "Q: QUIT");
    attroff(COLOR_PAIR(7));
    attroff(A_BOLD);
    refresh();
    return (0);
}

int update_ncurses(vm_t *vm)
{
    int c = 0;

    while (1) {
        update_windows(vm);
        c = getch();
        if (c == 'e')
            vm->running = 0;
        if (c == 'q')
            return (42);
        if (c == 'w' || (c == 's' && !vm->running)) {
            vm->running = c == 'w' ? 1 : 0;
            break;
        }
        if (vm->running)
            break;
    }
    return (0);
}