/*
** EPITECH PROJECT, 2019
** vm
** File description:
** vm
*/

#include "../../include/vm.hpp"

int is_game_over(vm_t *vm)
{
    int alive = 0;
    champ_t *tmp = vm->champs;

    while (tmp) {
        if (!tmp->dead)
            alive += 1;
        tmp = tmp->next;
    }
    if (vm->cycle && vm->lives >= NBR_LIVE && alive > 1) {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->lives = 0;
    }
    if (vm->cycle_to_die <= 0)
        return (1);
    if (!alive)
        return (1);
    return (0);
}

int check_death(vm_t *vm)
{
    champ_t *tmp = vm->champs;

    while (tmp) {
        if (vm->cycle - tmp->last_live > vm->cycle_to_die) {
            tmp->dead = 1;
            pc_free(tmp->pc);
            tmp->pc = NULL;
        }
        tmp = tmp->next;
    }
    return (0);
}

int get_winner(vm_t *vm)
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
            !vm->graphic ? printf("The player %d(%s) has won.\n", tmp->nb,
                tmp->name) : 0;
            return (0);
        }
        tmp = tmp->next;
    }
    return (0);
}

int virtual_machine(vm_t *vm)
{
    while (!is_game_over(vm)) {
        if (vm->dump != -1 && vm->cycle == vm->dump)
            return (print_arena(vm));
        get_opcodes(vm);
        exec_opcodes(vm);
        check_death(vm);
        vm->cycle += 1;
    }
    get_winner(vm);
    return (0);
}