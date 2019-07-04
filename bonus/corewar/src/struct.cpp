/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct
*/

#include "../../include/vm.hpp"

int init_struct(vm_t *vm)
{
    vm->champs = NULL;
    memset(vm->board, 0, MEM_SIZE);
    memset(vm->gboard, 0, MEM_SIZE);
    vm->dump = -1;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->cycle = 0;
    vm->lives = 0;
    vm->graphic = 0;
    vm->last_live = 0;
    vm->running = 0;
    return (0);
}

int my_free_exit(vm_t *vm, int code)
{
    vm->champs ? champ_free(vm->champs) : 0;
    return (code);
}