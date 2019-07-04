/*
** EPITECH PROJECT, 2018
** my_memset
** File description:
** my_memset
*/

#include "my.h"

void *my_memset(void *ptr, int c, size_t n)
{
    register unsigned char *tmp = (unsigned char *)ptr;

    for (int i = 0; i < n + (n % 4 ? 4 - (n % 4) : 0); ++i)
        tmp[i] = c;
    return (ptr);
}