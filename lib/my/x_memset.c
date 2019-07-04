/*
** EPITECH PROJECT, 2018
** x_memset
** File description:
** x_memset
*/

#include "my.h"

void *x_memset(int c, size_t nmemb, size_t size)
{
    char *tmp = malloc(size * (nmemb + 1));
    int i = 0;

    if (tmp == NULL)
        return (NULL);
    while (i <= nmemb) {
        tmp[i] = c;
        ++i;
    }
    return (tmp);
}