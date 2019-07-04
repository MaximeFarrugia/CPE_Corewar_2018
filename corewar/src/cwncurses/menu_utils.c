/*
** EPITECH PROJECT, 2019
** menu
** File description:
** menu
*/

#include "../../../include/my.h"
#include "../../../include/vm.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <ncurses.h>
#include <time.h>

int init_all_pair(void)
{
    init_pair(1, 1, 0);
    init_pair(2, 2, 0);
    init_pair(3, 3, 0);
    init_pair(4, 4, 0);
    init_pair(5, 5, 0);
    init_pair(6, 6, 0);
    init_pair(7, 7, 0);
    init_pair(8, 8, 0);
    return (0);
}

int my_strlen_tab(char **tab)
{
    int i = 0;

    while (tab[i])
        i++;
    return (i);
}

int get_bytes(vm_t *ft)
{
    int fd = open(".bytes", O_RDONLY);
    int i = 0;
    char *s = NULL;

    while ((s = get_next_line(fd))) {
        i++;
        free(s);
    }
    close(fd);
    ft->bytes = malloc(sizeof(char *) * (i + 1));
    i = 0;
    fd = open(".bytes", O_RDONLY);
    while ((s = get_next_line(fd))) {
        ft->bytes[i] = my_strdup(s);
        i++;
        free(s);
    }
    ft->bytes[i] = NULL;
    return (0);
}

int free_array(char **tab)
{
    int i = 0;

    if (!tab)
        return (0);
    while (tab[i]) {
        free(tab[i]);
        i++;
    }
    free(tab);
    return (0);
}