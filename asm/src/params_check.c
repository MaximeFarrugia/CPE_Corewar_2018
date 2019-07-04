/*
** EPITECH PROJECT, 2019
** params_check
** File description:
** params_check
*/

#include "../../include/my.h"
#include "../../include/asm.h"

int param_is_reg(char *param)
{
    int reg = 0;

    if (*param != 'r')
        return (-1);
    if (!param[1])
        return (84);
    reg = my_getnbr(&param[1]);
    if (reg < 1 || reg > REG_NUMBER)
        return (-1);
    return (1);
}

int param_is_dir(char *param)
{
    if (*param != DIRECT_CHAR)
        return (-1);
    if (!param[1] || (param[1] == LABEL_CHAR && !param[2]))
        return (84);
    if (param_is_label(&param[1], 1) == 1)
        return (1);
    if ((param[1] == '-' || param[1] == '+') && my_str_isnum(&param[2]))
        return (1);
    if (param[1] != '-' && param[1] != '+' && my_str_isnum(&param[1]))
        return (1);
    return (-1);
}

int param_is_ind(char *param)
{
    if (*param == LABEL_CHAR && !param[1])
        return (84);
    if (param_is_label(param, 1) == 1)
        return (1);
    if ((*param == '-' || *param == '+') && my_str_isnum(&param[1]))
        return (1);
    if (*param != '-' && *param != '+' && my_str_isnum(param))
        return (1);
    return (-1);
}

int param_is_label(char *param, int mode)
{
    int i = 0;

    if (!mode && *param == LABEL_CHAR)
        return (-1);
    else if (mode && *param != LABEL_CHAR)
        return (-1);
    for (i = mode ? 1 : 0; param[i] && param[i] != LABEL_CHAR; ++i) {
        if (!my_str_contains(LABEL_CHARS, param[i]))
            return (-1);
    }
    if (!mode && param[i] == LABEL_CHAR && !param[i + 1])
        return (1);
    else if (mode && !param[i])
        return (1);
    return (-1);
}

int count_inst_params(char **tab, int nbr_args)
{
    int args = my_tab_size(tab) - 1;

    if (args != nbr_args || nbr_args > MAX_ARGS_NUMBER)
        return (-1);
    return (args);
}