/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** error_handling_parameter
*/

#include "../../include/my.h"
#include "../../include/vm.h"

int add_in_save(int nb)
{
    static int save[4] = { 0, 0, 0, 0 };
    int j = -1;

    if (nb <= 0 || nb > 4) {
        my_printf("-n argument %d is invalid.\n"
            "Enter a number between 1 and 4.\n", nb);
        return (1);
    }
    for (int i = 0; i < 4; ++i) {
        if (save[i] == nb) {
            my_printf("double definition of prog_number.\n");
            return (1);
        }
    }
    while (save[++j]);
    save[j] = nb;
    return (0);
}

int check_same_numbers(int ac, char **av)
{
    for (int i = 1; i < ac; ++i) {
        if (my_strcmp(av[i], "-n") == 0 && (i + 1) < ac &&
            add_in_save(my_getnbr(av[i + 1])) == 1)
            return (84);
    }
    return (0);
}

int is_n(char **av, int *i, int *nb_a, int *nb_n)
{
    if (av[*i][0] == '-') {
        *nb_n = ((my_strcmp("-n", av[*i]) == 0) ? *nb_n + 1 : *nb_n);
        *nb_a = ((my_strcmp("-a", av[*i]) == 0) ? *nb_a + 1 : *nb_a);
        if (my_strcmp(av[*i], "-g"))
            *i = *i + 1;
    } else {
        *nb_n = 0;
        *nb_a = 0;
        return (1);
    }
    return (0);
}

int check_n(int ac, char **av)
{
    int nb_n = 0;
    int nb_a = 0;
    int nb_file = 0;

    if (check_same_numbers(ac, av))
        return (84);
    for (int i = 1; i < ac; ++i) {
        nb_file += is_n(av, &i, &nb_a, &nb_n);
        if (nb_n > 1 || nb_a > 1 || nb_file > 4 ||
            (my_strcmp("-dump", av[i - 1]) == 0 && i >= ac)) {
            my_printf("Invalid option.\n");
            return (84);
        }
    }
    if (nb_n >= 1 || nb_a >= 1 || nb_file < 2) {
        my_printf("Invalid option.\n");
        return (84);
    }
    return (0);
}

int unused_after(int nb, int ac, char **av, int index)
{
    for (int i = index; i < ac; ++i) {
        if (my_strcmp(av[i], "-n") == 0 && (i + 1) < ac &&
            nb == my_getnbr(av[i + 1])) {
            return (0);
        }
    }
    return (1);
}