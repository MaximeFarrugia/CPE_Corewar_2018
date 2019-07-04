/*
** EPITECH PROJECT, 2018
** my_isneg
** File description:
** displays either N if the integer passed as parameter is negative
** P, if positive or null
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar('P');
    else
        my_putchar('N');
    return (0);
}
