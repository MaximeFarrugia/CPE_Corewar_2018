/*
** EPITECH PROJECT, 2019
** end_ncurses
** File description:
** end_ncurses
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"

int cw_get_winner(vm_t *vm)
{
    int last_live = 0;
    champ_t *tmp = vm->champs;

    while (tmp) {
        if (tmp->last_live > last_live)
            last_live = tmp->last_live;
        tmp = tmp->next;
    }
    tmp = vm->champs;
    while (tmp) {
        if (last_live && tmp->last_live == last_live) {
            return (tmp->nb);
        }
        tmp = tmp->next;
    }
    return (0);
}

int end_player(vm_t *vm, int widx, int win)
{
    champ_t *champ = get_champ_by_nb(vm, widx - 1);

    clean_window(vm->wins[widx]);
    box(vm->wins[widx], 0, 0);
    dctxt(vm->wins[widx], (vector2i_t){ 23, 1 }, "PLAYER ", widx - 1);
    dctxt(vm->wins[widx], (vector2i_t){ 1, 3 }, "Name      : ", 7);
    dctxt(vm->wins[widx], (vector2i_t){ 1, 5 }, "Last live : ", 7);
    dctxt(vm->wins[widx], (vector2i_t){ 1, 7 }, "Nbr live  : ", 7);
    dctxt(vm->wins[widx], (vector2i_t){ 1, 9 }, "Processes : ", 7);
    dctxt(vm->wins[widx], (vector2i_t){ 1, 11 }, "Status    : ", 7);
    dcnbr(vm->wins[widx], (vector2i_t){ 30, 1 }, widx - 1, widx - 1);
    dctxt(vm->wins[widx], (vector2i_t){ 13, 3 }, champ->name, widx - 1);
    dcnbr(vm->wins[widx], (vector2i_t){ 13, 5 }, champ->last_live, widx - 1);
    dcnbr(vm->wins[widx], (vector2i_t){ 13, 7 }, champ->total_lives, widx - 1);
    dcnbr(vm->wins[widx], (vector2i_t){ 13, 9 }, champ_processes(champ),
        widx - 1);
    dctxt(vm->wins[widx], (vector2i_t){ 13, 11 }, win == widx - 1 ? "WINNER" :
        "LOSER", win == widx - 1 ? 4 : 1);
    wrefresh(vm->wins[widx]);
    return (0);
}

int end_ncurses(vm_t *vm, int force)
{
    int winner = cw_get_winner(vm);

    cw_print_arena(vm);
    update_infos(vm, vm->running ? 20 : 16);
    for (int i = 1; i <= 4; ++i) {
        if (get_champ_by_nb(vm, i))
            end_player(vm, i + 1, winner);
    }
    while (!force && getch() == ERR);
    delwin(vm->wins[0]);
    delwin(vm->wins[1]);
    delwin(vm->wins[2]);
    delwin(vm->wins[3]);
    delwin(vm->wins[4]);
    delwin(vm->wins[5]);
    endwin();
    return (0);
}