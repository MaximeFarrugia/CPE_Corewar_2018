/*
** EPITECH PROJECT, 2019
** sub
** File description:
** sub
*/

#include "../../../include/vm.hpp"

int cwsub(vm_t *vm, pc_t *pc)
{
    int params[(2 * MAX_ARGS_NUMBER) + 1] = { 0 };
    int left = 0;
    int right = 0;

    if (get_parameters(vm, pc, params, 0) == 84)
        return ((pc->pc = (pc->pc + 1) % MEM_SIZE) | (pc->carry = 0));
    pc->pc = (pc->pc + params[2 * MAX_ARGS_NUMBER]) % MEM_SIZE;
    left = pc->reg[params[MAX_ARGS_NUMBER] - 1];
    right = pc->reg[params[1 + MAX_ARGS_NUMBER] - 1];
    pc->reg[params[2 + MAX_ARGS_NUMBER] - 1] = left - right;
    return ((pc->carry = (left - right) ? 0 : 1));
}