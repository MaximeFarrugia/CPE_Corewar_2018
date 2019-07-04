/*
** EPITECH PROJECT, 2019
** get_parameters
** File description:
** get_parameters
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"

int param_to_int(vm_t *vm, int pc, int size)
{
    int nb = 0;
    int tmp = NEG(pc);

    for (int i = 0; i < size; ++i) {
        nb |= (vm->board[NEG((tmp + i) % MEM_SIZE)] <<
            (8 * (3 - i - (3 - (size - 1)))));
    }
    return (size == 2 ? (int16_t)nb : nb);
}

int calculate_params_bytes(int *params, int index)
{
    int count = 0;
    int tmp = index ? 2 : DIR_SIZE;

    for (int i = 0; i < MAX_ARGS_NUMBER; ++i) {
        count += params[i] == T_REG ? 1 : 0;
        count += params[i] == T_DIR ? tmp : 0;
        count += params[i] == T_IND - 1 ? IND_SIZE : 0;
    }
    params[2 * MAX_ARGS_NUMBER] = count + 2;
    return (0);
}

int get_params_values(vm_t *vm, int pc, int *params, int index)
{
    int off = 0;
    int tmp = index ? 2 : DIR_SIZE;

    for (int i = 0; i < MAX_ARGS_NUMBER; ++i) {
        off = params[i] == T_REG ? 1 : off;
        off = params[i] == T_DIR ? tmp : off;
        off = params[i] == T_IND - 1 ? IND_SIZE : off;
        params[i + MAX_ARGS_NUMBER] = param_to_int(vm, NEG(pc % MEM_SIZE), off);
        pc += off;
        off = 0;
    }
    return (0);
}

int get_optab_idx(char code)
{
    for (int i = 0; op_tab[i].code; ++i) {
        if (op_tab[i].code == code)
            return (i);
    }
    return (-1);
}

int get_parameters(vm_t *vm, pc_t *pc, int *params, int index)
{
    int desc = vm->board[(pc->pc + 1) % MEM_SIZE];
    int idx = get_optab_idx(pc->opcode);
    char tmp = 0;

    for (int i = 0; i < op_tab[idx].nbr_args; ++i) {
        params[i] = ((desc >> (2 * (3 - i)) & 0x03));
        tmp = params[i] == T_IND - 1 ? T_IND : params[i];
        if (!tmp || (tmp & op_tab[idx].type[i]) != tmp)
            return (84);
    }
    calculate_params_bytes(params, index);
    get_params_values(vm, NEG((pc->pc + 2) % MEM_SIZE), params, index);
    for (int i = 0; i < op_tab[idx].nbr_args; ++i) {
        if (params[i] == T_REG && (params[i + MAX_ARGS_NUMBER] < 1 ||
            params[i + MAX_ARGS_NUMBER] > REG_NUMBER))
            return (84);
    }
    return (0);
}