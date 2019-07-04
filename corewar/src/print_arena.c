/*
** EPITECH PROJECT, 2019
** print_arena
** File description:
** print_arena
*/

#include "../../include/my.h"
#include "../../include/vm.h"

int my_int_size(int nbr)
{
    int len = 0;

    do {
        len += 1;
        nbr >>= 4;
    } while (nbr);
    return (len);
}

int print_line_number(int index, int ctw)
{
    my_printf("%X", index);
    for (int i = my_int_size(index); i < ctw; ++i)
        my_printf(" ");
    my_printf(" : ");
    return (0);
}

int print_arena(vm_t *vm)
{
    char hex_array[16] = "0123456789ABCDEF";
    int chars_to_write = my_int_size(MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; ++i) {
        if (!(i % 32))
            print_line_number(i, chars_to_write);
        my_printf("%c", hex_array[((vm->board[i] >> 4) & 0x0f)]);
        my_printf("%c ", hex_array[(vm->board[i] & 0x0f)]);
        !((i + 1) % 32) ? my_printf("\n") : 0;
    }
    if (vm->lives > 0)
        get_winner(vm);
    return (0);
}