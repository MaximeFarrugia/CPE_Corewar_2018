/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include "../../include/vm.hpp"

int rint_free(void *ptr)
{
    if (ptr)
        free(ptr);
    return (0);
}

int tab_contains(const char **tab, char *str)
{
    for (int i = 0; tab && tab[i]; ++i) {
        if (!strcmp(tab[i], str))
            return (1);
    }
    return (0);
}