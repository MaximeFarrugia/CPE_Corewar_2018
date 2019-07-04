/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** usage
*/

#include "../../include/vm.hpp"

void usage(char *name)
{
    printf("USAGE\n\t%s [-dump nbr_cycle] ", name);
    printf("[[-n prog_number] [-a load_address] prog_name] ...\n");
    printf("\nDESCRIPTION\n\t-dump nbr_cycle dumps the memory");
    printf(" after the nbr_cycle execution (if the round isn’t\n");
    printf("\t\t\talready over) with the following format: 32 bytes/");
    printf("line in\n\t\t\thexadecimal (A0BCDEFE1DD3...)\n");
    printf("\t-n prog_number  sets the next program’s number.");
    printf(" By default, the first free number\n");
    printf("\t\t\tin the parameter order\n");
    printf("\t-a load_address sets the next program’s ");
    printf("loading address. When no address is\n");
    printf("\t\t\tspecified, optimize the addresses so that the ");
    printf("processes are as far\n\t\t\taway from each other as possible.");
    printf(" The addresses are MEM_SIZE modulo\n");
}
