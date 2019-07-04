/*
** EPITECH PROJECT, 2019
** lfork
** File description:
** lfork
*/

#include "../../../include/vm.hpp"

int cwlfork(vm_t *vm, pc_t *pc)
{
    int tmp = pc->pc;
    int off = param_to_int(vm, (pc->pc + 1) % MEM_SIZE, 2);

    pc->pc = (pc->pc + 3) % MEM_SIZE;
    add_pc(&pc, (tmp + (off - 1)) % MEM_SIZE, pc->reg, pc);
    pc = pc->next;
    pc->opcode = get_opcode(vm, pc->pc);
    pc->cycle_wait = update_cycle_wait(pc->opcode, 0);
    return (0);
}