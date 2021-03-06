/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** create list
*/

#include "../../include/my.h"
#include "../../include/vm.h"

int get_nb_champ(int ac, char **av)
{
    int nb_champ = 0;
    char *flags[] = { "-a", "-n", "-dump", "-g", NULL };

    for (int i = 1; i < ac; ++i) {
        if (tab_contains(flags, av[i]))
            my_strcmp(av[i], "-g") ? i++ : 0;
        else
            nb_champ++;
    }
    return (nb_champ);
}

int change_param(char **param, vm_t *vm, int *address, int *number)
{
    if (my_strcmp(param[0], "-a") == 0)
        *address = my_getnbr(param[1]);
    if (my_strcmp(param[0], "-n") == 0)
        *number = my_getnbr(param[1]);
    if (my_strcmp(param[0], "-dump") == 0) {
        vm->dump = my_getnbr(param[1]);
        if (vm->dump >= 0)
            return (0);
        my_printf("-dump argument %d is invalid."
        " Please enter a positive number.\n", vm->dump);
        return (1);
    }
    if (my_strcmp(param[0], "-g") == 0)
        vm->graphic = 1;
    return (0);
}

int new_number(int number, int ac, char **av, int index)
{
    static int used[4] = {0};

    if (number >= 0)
        used[number - 1] = 1;
    for (int i = 0; i < 4; ++i) {
        if (!used[i] && unused_after(i + 1, ac, av, index)) {
            used[i] = 1;
            return (i + 1);
        }
    }
    return (1);
}

int new_address(int nb_champ, vm_t *vm)
{
    static int i = 0;
    int new;
    int go = 1;
    int count = 0;

    i++;
    new = i * MEM_SIZE / nb_champ;
    while (go) {
        go = 0;
        for (int j = 0; !go && j < SIZE_MAX_CHAMPION; ++j)
            (vm->board[(new + j) % MEM_SIZE]) ? go = 1 : 0;
        if (go)
            new = (new + 1) % MEM_SIZE;
        if (++count > MEM_SIZE * 2)
            return (new % MEM_SIZE);
    }
    return (new % MEM_SIZE);
}

int create_list(int ac, char **av, vm_t *vm)
{
    int nb_champ = get_nb_champ(ac, av);
    int address = 0;
    int number = new_number(-1, ac, av, 0);
    char *flags[] = { "-a", "-n", "-dump", "-g", NULL };

    if (check_n(ac, av))
        return (84);
    for (int i = 1; i < ac; ++i) {
        if (tab_contains(flags, av[i])) {
            number = (change_param(&av[i], vm, &address, &number) == 1)
                ? 84 : number;
            my_strcmp(av[i], "-g") ? i++ : 0;
        } else {
            number = create_champ(vm, number, address, av[i]) ? 84 : number;
            number = number != 84 ? new_number(number, ac, av, i + 1) : number;
            address = new_address(nb_champ, vm);
        }
        if (number == 84)
            return (84);
    }
    return (0);
}