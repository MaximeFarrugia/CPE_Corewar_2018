/*
** EPITECH PROJECT, 2019
** sti
** File description:
** sti
*/

#include "../../../include/vm.hpp"

int cwsti(vm_t *vm, pc_t *pc)
{
    int params[(2 * MAX_ARGS_NUMBER) + 1] = { 0 };
    int off = 0;
    int tmp = pc->pc;

    if (get_parameters(vm, pc, params, 1) == 84)
        return ((pc->pc = (pc->pc + 1) % MEM_SIZE));
    pc->pc = (pc->pc + params[2 * MAX_ARGS_NUMBER]) % MEM_SIZE;
    if (params[1] == T_REG)
        off = pc->reg[params[1 + MAX_ARGS_NUMBER] - 1];
    else
        off = params[1] == T_DIR ? params[1 + MAX_ARGS_NUMBER] :
            param_to_int(vm, (tmp + params[1 + MAX_ARGS_NUMBER] % IDX_MOD) %
            MEM_SIZE, IND_SIZE);
    if (params[2] == T_REG)
        off += pc->reg[params[2 + MAX_ARGS_NUMBER] - 1];
    else
        off += params[2 + MAX_ARGS_NUMBER];
    write_in_mem(vm, NEG((tmp + off % IDX_MOD) % MEM_SIZE),
        pc->reg[params[MAX_ARGS_NUMBER] - 1], REG_SIZE | (pc->p->nb << 4));
    return (0);
}