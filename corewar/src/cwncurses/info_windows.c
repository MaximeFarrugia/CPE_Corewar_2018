/*
** EPITECH PROJECT, 2019
** info_windows
** File description:
** info_windows
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"

int update_infos(vm_t *vm, int tpos)
{
    champ_t *champ = get_champ_by_nb(vm, vm->last_live);

    clean_window(vm->wins[1]);
    box(vm->wins[1], 0, 0);
    dctxt(vm->wins[1], (vector2i_t){ tpos, 1 }, "GLOBAL INFORMATIONS", 6);
    dctxt(vm->wins[1], (vector2i_t){ 1, 3 }, "Total cycles : ", 7);
    dctxt(vm->wins[1], (vector2i_t){ 1, 5 }, "Cycle to die : ", 7);
    dctxt(vm->wins[1], (vector2i_t){ 1, 7 }, "Cycle delta  : ", 7);
    dctxt(vm->wins[1], (vector2i_t){ 1, 9 }, "Nbr live     : ", 7);
    dctxt(vm->wins[1], (vector2i_t){ 1, 11 }, "Processes    : ", 7);
    dctxt(vm->wins[1], (vector2i_t){ 1, 13 }, "Last live    : ", 7);
    tpos == 16 ? dctxt(vm->wins[1], (vector2i_t){ 36, 1 }, "(PAUSED)", 1) : 0;
    dcnbr(vm->wins[1], (vector2i_t){ 16, 3 }, vm->cycle, 6);
    dcnbr(vm->wins[1], (vector2i_t){ 16, 5 }, vm->cycle_to_die, 6);
    dcnbr(vm->wins[1], (vector2i_t){ 16, 7 }, CYCLE_DELTA, 6);
    dcnbr(vm->wins[1], (vector2i_t){ 16, 9 }, vm->lives, 6);
    dcnbr(vm->wins[1], (vector2i_t){ 16, 11 }, total_processes(vm), 6);
    dctxt(vm->wins[1], (vector2i_t){ 16, 13 }, champ ? champ->name : "none",
        vm->last_live);
    return (wrefresh(vm->wins[1]));
}

int update_pone(vm_t *vm)
{
    champ_t *champ = get_champ_by_nb(vm, 1);

    clean_window(vm->wins[2]);
    box(vm->wins[2], 0, 0);
    dctxt(vm->wins[2], (vector2i_t){ 23, 1 }, "PLAYER 1", 1);
    dctxt(vm->wins[2], (vector2i_t){ 1, 3 }, "Name      : ", 7);
    dctxt(vm->wins[2], (vector2i_t){ 1, 5 }, "Last live : ", 7);
    dctxt(vm->wins[2], (vector2i_t){ 1, 7 }, "Nbr live  : ", 7);
    dctxt(vm->wins[2], (vector2i_t){ 1, 9 }, "Processes : ", 7);
    dctxt(vm->wins[2], (vector2i_t){ 1, 11 }, "Status    : ", 7);
    if (!champ)
        return (wrefresh(vm->wins[2]));
    dctxt(vm->wins[2], (vector2i_t){ 13, 3 }, champ->name, 1);
    dcnbr(vm->wins[2], (vector2i_t){ 13, 5 }, champ->last_live, 1);
    dcnbr(vm->wins[2], (vector2i_t){ 13, 7 }, champ->total_lives, 1);
    dcnbr(vm->wins[2], (vector2i_t){ 13, 9 }, champ_processes(champ), 1);
    dctxt(vm->wins[2], (vector2i_t){ 13, 11 }, champ->dead ? "dead" : "alive",
        champ->dead ? 1 : 3);
    wrefresh(vm->wins[2]);
    return (0);
}

int update_ptwo(vm_t *vm)
{
    champ_t *champ = get_champ_by_nb(vm, 2);

    clean_window(vm->wins[3]);
    box(vm->wins[3], 0, 0);
    dctxt(vm->wins[3], (vector2i_t){ 23, 1 }, "PLAYER 2", 2);
    dctxt(vm->wins[3], (vector2i_t){ 1, 3 }, "Name      : ", 7);
    dctxt(vm->wins[3], (vector2i_t){ 1, 5 }, "Last live : ", 7);
    dctxt(vm->wins[3], (vector2i_t){ 1, 7 }, "Nbr live  : ", 7);
    dctxt(vm->wins[3], (vector2i_t){ 1, 9 }, "Processes : ", 7);
    dctxt(vm->wins[3], (vector2i_t){ 1, 11 }, "Status    : ", 7);
    if (!champ)
        return (wrefresh(vm->wins[3]));
    dctxt(vm->wins[3], (vector2i_t){ 13, 3 }, champ->name, 2);
    dcnbr(vm->wins[3], (vector2i_t){ 13, 5 }, champ->last_live, 2);
    dcnbr(vm->wins[3], (vector2i_t){ 13, 7 }, champ->total_lives, 2);
    dcnbr(vm->wins[3], (vector2i_t){ 13, 9 }, champ_processes(champ), 2);
    dctxt(vm->wins[3], (vector2i_t){ 13, 11 }, champ->dead ? "dead" : "alive",
        champ->dead ? 1 : 3);
    wrefresh(vm->wins[3]);
    return (0);
}

int update_pthree(vm_t *vm)
{
    champ_t *champ = get_champ_by_nb(vm, 3);

    clean_window(vm->wins[4]);
    box(vm->wins[4], 0, 0);
    dctxt(vm->wins[4], (vector2i_t){ 23, 1 }, "PLAYER 3", 3);
    dctxt(vm->wins[4], (vector2i_t){ 1, 3 }, "Name      : ", 7);
    dctxt(vm->wins[4], (vector2i_t){ 1, 5 }, "Last live : ", 7);
    dctxt(vm->wins[4], (vector2i_t){ 1, 7 }, "Nbr live  : ", 7);
    dctxt(vm->wins[4], (vector2i_t){ 1, 9 }, "Processes : ", 7);
    dctxt(vm->wins[4], (vector2i_t){ 1, 11 }, "Status    : ", 7);
    if (!champ)
        return (wrefresh(vm->wins[4]));
    dctxt(vm->wins[4], (vector2i_t){ 13, 3 }, champ->name, 3);
    dcnbr(vm->wins[4], (vector2i_t){ 13, 5 }, champ->last_live, 3);
    dcnbr(vm->wins[4], (vector2i_t){ 13, 7 }, champ->total_lives, 3);
    dcnbr(vm->wins[4], (vector2i_t){ 13, 9 }, champ_processes(champ), 3);
    dctxt(vm->wins[4], (vector2i_t){ 13, 11 }, champ->dead ? "dead" : "alive",
        champ->dead ? 1 : 3);
    wrefresh(vm->wins[4]);
    return (0);
}

int update_pfour(vm_t *vm)
{
    champ_t *champ = get_champ_by_nb(vm, 4);

    clean_window(vm->wins[5]);
    box(vm->wins[5], 0, 0);
    dctxt(vm->wins[5], (vector2i_t){ 23, 1 }, "PLAYER 4", 4);
    dctxt(vm->wins[5], (vector2i_t){ 1, 3 }, "Name      : ", 7);
    dctxt(vm->wins[5], (vector2i_t){ 1, 5 }, "Last live : ", 7);
    dctxt(vm->wins[5], (vector2i_t){ 1, 7 }, "Nbr live  : ", 7);
    dctxt(vm->wins[5], (vector2i_t){ 1, 9 }, "Processes : ", 7);
    dctxt(vm->wins[5], (vector2i_t){ 1, 11 }, "Status    : ", 7);
    if (!champ)
        return (wrefresh(vm->wins[5]));
    dctxt(vm->wins[5], (vector2i_t){ 13, 3 }, champ->name, 4);
    dcnbr(vm->wins[5], (vector2i_t){ 13, 5 }, champ->last_live, 4);
    dcnbr(vm->wins[5], (vector2i_t){ 13, 7 }, champ->total_lives, 4);
    dcnbr(vm->wins[5], (vector2i_t){ 13, 9 }, champ_processes(champ), 4);
    dctxt(vm->wins[5], (vector2i_t){ 13, 11 }, champ->dead ? "dead" : "alive",
        champ->dead ? 1 : 3);
    wrefresh(vm->wins[5]);
    return (0);
}