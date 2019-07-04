/*
** EPITECH PROJECT, 2019
** aff
** File description:
** aff
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"

int cwaff(vm_t *vm, pc_t *pc)
{
    int params[(2 * MAX_ARGS_NUMBER) + 1] = { 0 };
    char c = 0;

    if (get_parameters(vm, pc, params, 1) == 84)
        return ((pc->pc = (pc->pc + 1) % MEM_SIZE));
    pc->pc = (pc->pc + params[2 * MAX_ARGS_NUMBER]) % MEM_SIZE;
    c = pc->reg[params[MAX_ARGS_NUMBER] - 1] % 256;
    my_printf("%c", c);
    return (0);
}