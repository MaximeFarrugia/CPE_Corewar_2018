/*
** EPITECH PROJECT, 2019
** write_in_mem
** File description:
** write_in_mem
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"

int write_in_mem(vm_t *vm, int pc, int data, int size)
{
    int tmp = NEG(pc);

    for (int i = 0; i < (size & 0x0f); ++i) {
        vm->board[NEG((tmp + i) % MEM_SIZE)] =
            (data >> 8 * ((size - 1) - i)) & 0xff;
        vm->gboard[NEG((tmp + i) % MEM_SIZE)] = (size >> 4) & 0x0f;
    }
    return (0);
}