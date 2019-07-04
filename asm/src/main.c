/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../../include/my.h"
#include "../../include/asm.h"

int rint_free(void *ptr)
{
    ptr ? free(ptr) : 0;
    return (0);
}

int display_help(int ac, char **av)
{
    for (int i = 1; i < ac; ++i) {
        if (!my_strcmp(av[i], "-h")) {
            my_printf("USAGE\n\t%s file_name[.s]\n\nDESCRIPTION\n\t"
                "file_name\tfile in assembly language to be converted "
                "into file_name.cor, an executable in the Virtual Machine.\n",
                av[0]);
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    asm_t casm;
    int rc = 0;

    if (ac < 2)
        return (84);
    if (display_help(ac, av))
        return (0);
    for (int i = 1; i < ac; ++i) {
        init_struct(&casm);
        if (file_handling(&casm, av[i]) == 84)
            rc = 84;
        my_free_exit(&casm, 0);
    }
    return (rc);
}