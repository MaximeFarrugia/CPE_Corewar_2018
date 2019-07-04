/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include "../../include/my.h"
#include "../../include/vm.h"

int rint_free(void *ptr)
{
    ptr ? free(ptr) : 0;
    return (0);
}

int tab_contains(char **tab, char *str)
{
    for (int i = 0; tab && tab[i]; ++i) {
        if (!my_strcmp(tab[i], str))
            return (1);
    }
    return (0);
}