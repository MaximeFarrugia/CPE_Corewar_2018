/*
** EPITECH PROJECT, 2019
** live
** File description:
** live
*/

#include "../../../include/vm.hpp"

int cwlive(vm_t *vm, pc_t *pc)
{
    int nb = 0;
    champ_t *tmp = vm->champs;

    nb = param_to_int(vm, (pc->pc + 1) % MEM_SIZE, 4);
    pc->pc = (pc->pc + 5) % MEM_SIZE;
    if (nb < 1 || nb > 4)
        return (0);
    while (tmp) {
        if (tmp->nb == nb) {
            if (!vm->graphic)
                printf("The player %d(%s) is alive.\n", nb, tmp->name);
            tmp->last_live = vm->cycle;
            vm->lives += 1;
            tmp->total_lives += 1;
            vm->last_live = nb;
        }
        tmp = tmp->next;
    }
    return (0);
}