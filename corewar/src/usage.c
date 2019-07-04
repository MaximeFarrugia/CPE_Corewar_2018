/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** usage
*/

#include "../../include/my.h"
#include "../../include/vm.h"

void usage(char *name)
{
    my_printf("USAGE\n\t%s [-dump nbr_cycle] ", name);
    my_putstr("[[-n prog_number] [-a load_address] prog_name] ...\n");
    my_putstr("\nDESCRIPTION\n\t-dump nbr_cycle dumps the memory");
    my_putstr(" after the nbr_cycle execution (if the round isn’t\n");
    my_putstr("\t\t\talready over) with the following format: 32 bytes/");
    my_putstr("line in\n\t\t\thexadecimal (A0BCDEFE1DD3...)\n");
    my_putstr("\t-n prog_number  sets the next program’s number.");
    my_putstr(" By default, the first free number\n");
    my_putstr("\t\t\tin the parameter order\n");
    my_putstr("\t-a load_address sets the next program’s ");
    my_putstr("loading address. When no address is\n");
    my_putstr("\t\t\tspecified, optimize the addresses so that the ");
    my_putstr("processes are as far\n\t\t\taway from each other as possible.");
    my_putstr(" The addresses are MEM_SIZE modulo\n");
}
