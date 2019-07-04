/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct
*/

#include "../../include/my.h"
#include "../../include/asm.h"

int init_struct(asm_t *casm)
{
    casm->filename = NULL;
    casm->content = NULL;
    casm->insts = NULL;
    return (0);
}

int my_free_exit(asm_t *casm, int code)
{
    casm->filename ? free(casm->filename) : 0;
    casm->content ? ll_free(casm->content) : 0;
    casm->insts ? inst_free(casm->insts) : 0;
    return (code);
}