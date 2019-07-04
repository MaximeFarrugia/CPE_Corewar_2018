/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"

int champ_processes(champ_t *champ)
{
    pc_t *tmp = champ->pc;
    int count = 0;

    while (tmp) {
        count += 1;
        tmp = tmp->next;
    }
    return (count);
}

int total_processes(vm_t *vm)
{
    champ_t *champ = vm->champs;
    pc_t *pc = champ->pc;
    int count = 0;

    while (champ) {
        pc = champ->pc;
        while (pc) {
            count += 1;
            pc = pc->next;
        }
        champ = champ->next;
    }
    return (count);
}

champ_t *get_champ_by_nb(vm_t *vm, int nb)
{
    champ_t *tmp = vm->champs;

    while (tmp && tmp->nb != nb)
        tmp = tmp->next;
    return (tmp);
}