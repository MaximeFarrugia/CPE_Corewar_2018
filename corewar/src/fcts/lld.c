/*
** EPITECH PROJECT, 2019
** lld
** File description:
** lld
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"

int cwlld(vm_t *vm, pc_t *pc)
{
    int params[(2 * MAX_ARGS_NUMBER) + 1] = { 0 };
    int off = 0;
    int tmp = pc->pc;

    if (get_parameters(vm, pc, params, 0) == 84)
        return ((pc->pc = (pc->pc + 1) % MEM_SIZE) | (pc->carry = 0));
    pc->pc = (pc->pc + params[2 * MAX_ARGS_NUMBER]) % MEM_SIZE;
    if (params[0] == T_DIR)
        off = params[MAX_ARGS_NUMBER];
    else
        off = param_to_int(vm,
            (tmp + params[MAX_ARGS_NUMBER]) % MEM_SIZE, REG_SIZE);
    pc->reg[params[1 + MAX_ARGS_NUMBER] - 1] = off;
    return ((pc->carry = off ? 0 : 1));
}