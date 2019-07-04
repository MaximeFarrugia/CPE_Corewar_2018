/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** allocate memory and copy the strings given as parameter in it
*/

#include "my.h"

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *result = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (!result)
        return (NULL);
    while (str[i] != '\0') {
        result[i] = str[i];
        ++i;
    }
    result[i] = '\0';
    return (result);
}
