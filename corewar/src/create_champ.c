/*
** EPITECH PROJECT, 2019
** create_champ
** File description:
** create_champ
*/

#include "../../include/my.h"
#include "../../include/vm.h"

int check_magic(vm_t *vm, int fd)
{
    my_memset(&vm->header, 0, sizeof(header_t));
    if (read(fd, &vm->header, sizeof(header_t)) < (ssize_t)sizeof(header_t))
        return (84);
    if ((int)vm->header.magic != (int)be32toh(COREWAR_EXEC_MAGIC))
        return (84);
    return (0);
}

int check_address(vm_t *vm, int address)
{
    int count = 0;

    for (int i = address; count < (int)be32toh(vm->header.prog_size);
        ++i, ++count) {
        if (i >= MEM_SIZE)
            i %= MEM_SIZE;
        if (vm->board[i])
            return (84);
    }
    return (0);
}

int put_champ_in_board(vm_t *vm, int fd, int address, int nb)
{
    char s[1] = { 0 };

    for (int i = address; read(fd, &s, 1) > 0; ++i) {
        if (i >= MEM_SIZE)
            i %= MEM_SIZE;
        vm->board[i] = *s;
        vm->gboard[i] = nb;
    }
    return (0);
}

int create_champ(vm_t *vm, int number, int address, char *file)
{
    int fd = 0;

    if ((fd = open(file, O_RDONLY)) == -1)
        return (84);
    if (check_magic(vm, fd) == 84)
        return (close(fd) | 84);
    if (check_address(vm, address) == 84)
        return (close(fd) | 84);
    if (champ_add_node(&vm->champs, number, vm->header.prog_name,
        address % MEM_SIZE))
        return (close(fd) | 84);
    put_champ_in_board(vm, fd, address, number);
    close(fd);
    return (0);
}