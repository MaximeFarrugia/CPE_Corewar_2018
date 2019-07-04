/*
** EPITECH PROJECT, 2019
** st
** File description:
** st
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"

int cwst(vm_t *vm, pc_t *pc)
{
    int params[(2 * MAX_ARGS_NUMBER) + 1] = { 0 };
    int off = 0;
    int tmp = pc->pc;

    if (get_parameters(vm, pc, params, 0) == 84)
        return ((pc->pc = (pc->pc + 1) % MEM_SIZE));
    pc->pc = (pc->pc + params[2 * MAX_ARGS_NUMBER]) % MEM_SIZE;
    off = (params[1] == T_REG ? 0 : params[1 + MAX_ARGS_NUMBER]);
    if (params[1] != T_REG) {
        write_in_mem(vm, (tmp + off % IDX_MOD) % MEM_SIZE,
            pc->reg[params[MAX_ARGS_NUMBER] - 1], REG_SIZE | (pc->p->nb << 4));
        return (0);
    }
    pc->reg[params[1 + MAX_ARGS_NUMBER] - 1] =
        pc->reg[params[MAX_ARGS_NUMBER] - 1];
    return (0);
}