/*
** EPITECH PROJECT, 2019
** get_opcodes
** File description:
** get_opcodes
*/

#include "../../include/my.h"
#include "../../include/vm.h"

int get_opcode(vm_t *vm, int pc)
{
    int i = 0;

    for (; op_tab[i].code; ++i) {
        if (op_tab[i].code == vm->board[pc])
            break;
    }
    return (op_tab[i].code);
}

int update_cycle_wait(int opcode, int cycle_wait)
{
    int i = 0;

    if (cycle_wait > 0)
        return (cycle_wait);
    for (; op_tab[i].code; ++i) {
        if (op_tab[i].code == opcode)
            break;
    }
    return (op_tab[i].nbr_cycles);
}

int get_opcodes(vm_t *vm)
{
    champ_t *champ = vm->champs;
    pc_t *pc = champ->pc;

    while (champ) {
        pc = champ->pc;
        while (pc) {
            pc->opcode = get_opcode(vm, pc->pc);
            pc->cycle_wait = update_cycle_wait(pc->opcode, pc->cycle_wait);
            pc = pc->next;
        }
        champ = champ->next;
    }
    return (0);
}