/*
** EPITECH PROJECT, 2019
** or
** File description:
** or
*/

#include "../../../include/vm.hpp"

int cwor(vm_t *vm, pc_t *pc)
{
    int params[(2 * MAX_ARGS_NUMBER) + 1] = { 0 };
    int tmp = pc->pc;
    int left = 0;
    int right = 0;

    if (get_parameters(vm, pc, params, 0) == 84)
        return ((pc->pc = (pc->pc + 1) % MEM_SIZE) | (pc->carry = 0));
    pc->pc = (pc->pc + params[2 * MAX_ARGS_NUMBER]) % MEM_SIZE;
    if (params[0] == T_REG)
        left = pc->reg[params[MAX_ARGS_NUMBER] - 1];
    else
        left = params[0] == T_DIR ? params[MAX_ARGS_NUMBER] : param_to_int(vm,
            (tmp + params[MAX_ARGS_NUMBER] % IDX_MOD) % MEM_SIZE, IND_SIZE);
    if (params[1] == T_REG)
        right = pc->reg[params[1 + MAX_ARGS_NUMBER] - 1];
    else
        right = params[1] == T_DIR ? params[1 + MAX_ARGS_NUMBER] : param_to_int(
            vm, (tmp + params[MAX_ARGS_NUMBER] % IDX_MOD) % MEM_SIZE, IND_SIZE);
    pc->reg[params[2 + MAX_ARGS_NUMBER] - 1] = left | right;
    return ((pc->carry = (left | right) ? 0 : 1));
}