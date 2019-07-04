/*
** EPITECH PROJECT, 2019
** lldi
** File description:
** lldi
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"

int cwlldi(vm_t *vm, pc_t *pc)
{
    int params[(2 * MAX_ARGS_NUMBER) + 1] = { 0 };
    int off = 0;
    int first = 0;
    int tmp = pc->pc;
    int s = 0;

    if (get_parameters(vm, pc, params, 1) == 84)
        return ((pc->pc = (pc->pc + 1) % MEM_SIZE) | (pc->carry = 0));
    pc->pc = (pc->pc + params[2 * MAX_ARGS_NUMBER]) % MEM_SIZE;
    if (params[0] == T_REG)
        first = pc->reg[params[MAX_ARGS_NUMBER] - 1];
    else
        first = params[0] == T_DIR ? params[MAX_ARGS_NUMBER] : param_to_int(vm,
            (tmp + params[MAX_ARGS_NUMBER]) % MEM_SIZE, IND_SIZE);
    s = first + (params[1] == T_DIR ? params[1 + MAX_ARGS_NUMBER] :
        pc->reg[params[1 + MAX_ARGS_NUMBER] - 1]);
    off = param_to_int(vm, (tmp + s) % MEM_SIZE, REG_SIZE);
    pc->reg[params[2 + MAX_ARGS_NUMBER] - 1] = off;
    return ((pc->carry = off ? 0 : 1));
}