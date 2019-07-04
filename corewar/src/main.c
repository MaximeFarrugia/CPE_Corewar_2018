/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../../include/my.h"
#include "../../include/vm.h"

int main(int ac, char **av)
{
    vm_t vm;
    int rc = 0;

    init_struct(&vm);
    if (create_list(ac, av, &vm))
        return (my_free_exit(&vm, 84));
    if (vm.graphic && ((rc = menu(&vm)) == 42 || init_ncurses(&vm) == 84))
        return (my_free_exit(&vm, rc == 42 ? 0 : 84));
    rc = virtual_machine(&vm);
    vm.graphic ? end_ncurses(&vm, rc) : 0;
    return (my_free_exit(&vm, 0));
}