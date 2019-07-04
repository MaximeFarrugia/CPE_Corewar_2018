/*
** EPITECH PROJECT, 2019
** zjmp
** File description:
** zjmp
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"

int cwzjmp(vm_t *vm, pc_t *pc)
{
    int off = param_to_int(vm, (pc->pc + 1) % MEM_SIZE, 2);

    if (!pc->carry)
        return ((pc->pc = (pc->pc + 3) % MEM_SIZE));
    pc->pc = (pc->pc + off % IDX_MOD) % MEM_SIZE;
    return (0);
}