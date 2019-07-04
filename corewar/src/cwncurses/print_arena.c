/*
** EPITECH PROJECT, 2019
** print_arena
** File description:
** print_arena
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"

int is_idx_pc(vm_t *vm, int idx)
{
    champ_t *champ = vm->champs;
    pc_t *pc = champ->pc;

    while (champ) {
        pc = champ->pc;
        while (pc) {
            if (pc->pc == idx)
                return (1);
            pc = pc->next;
        }
        champ = champ->next;
    }
    return (0);
}

int cw_print_byte(vm_t *vm, int idx, int x, int y)
{
    char hex_array[16] = "0123456789ABCDEF";

    wattron(vm->wins[0], COLOR_PAIR(is_idx_pc(vm, idx) ?
        5 : vm->gboard[idx]));
    vm->gboard[idx] ? wattron(vm->wins[0], A_BOLD) : 0;
    mvwprintw(vm->wins[0], y, x, "%c",
        hex_array[((vm->board[idx] >> 4) & 0x0f)]);
    mvwprintw(vm->wins[0], y, x + 1, "%c",
        hex_array[(vm->board[idx] & 0x0f)]);
    wattroff(vm->wins[0], COLOR_PAIR(is_idx_pc(vm, idx) ?
        5 : vm->gboard[idx]));
    vm->gboard[idx] ? wattroff(vm->wins[0], A_BOLD) : 0;
    return (0);
}

int cw_print_arena(vm_t *vm)
{
    int x = 1;
    int y = 1;

    box(vm->wins[0], 0, 0);
    for (int i = 0; i < MEM_SIZE; ++i) {
        if (i && !(i % (MEM_SIZE / 64))) {
            y += 1;
            x = 1;
        }
        cw_print_byte(vm, i, x, y);
        x += 3;
    }
    wrefresh(vm->wins[0]);
    return (0);
}