/*
** EPITECH PROJECT, 2019
** exec_opcodes
** File description:
** exec_opcodes
*/

#include "../../include/vm.hpp"

int exec_opcode(vm_t *vm, pc_t *pc)
{
    int (*fcts[16])(vm_t *vm, pc_t *pc) = { &cwlive, &cwld, &cwst, &cwadd, &cwsub, &cwand, &cwor,
        &cwxor, &cwzjmp, &cwldi, &cwsti, &cwfork, &cwlld, &cwlldi,
        &cwlfork, &cwaff };

    if (!pc->opcode) {
        pc->pc += 1;
        return (0);
    }
    fcts[pc->opcode - 1](vm, pc);
    return (0);
}

int exec_opcodes(vm_t *vm)
{
    champ_t *champ = vm->champs;
    pc_t *pc = champ->pc;

    while (champ) {
        pc = champ->pc;
        while (pc) {
            pc->cycle_wait -= 1;
            pc->cycle_wait <= 0 ? exec_opcode(vm, pc) : 0;
            pc = pc->next;
        }
        champ = champ->next;
    }
    return (0);
}