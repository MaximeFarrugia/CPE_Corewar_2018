/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include "../../include/my.h"
#include "../../include/asm.h"

int my_getnbr_overflow(char *str)
{
    int i = 0;
    int neg = 0;
    int res = 0;

    for (i = 0; str[i] && (str[i] == '-' || str[i] == '+');
        neg += str[i] == '-' ? 1 : 0, ++i);
    neg = !neg || !(neg % 2) ? 0 : 1;
    for (; str[i] && str[i] >= '0' && str[i] <= '9'; ++i)
        res = res * 10 + str[i] - '0';
    return (neg && res ? res * -1 : res);
}

ll_t *find_next_inst(ll_t *cur)
{
    ll_t *tmp = cur;

    while (tmp) {
        if (tmp->tab && param_is_label(tmp->tab[0], 0) != 1)
            return (tmp);
        if (tmp->tab && param_is_label(tmp->tab[0], 0) == 1 && tmp->tab[1])
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

int tab_contains(char **tab, char *str)
{
    for (int i = 0; tab && tab[i]; ++i) {
        if (!my_strcmp(tab[i], str))
            return (1);
    }
    return (0);
}

char **tab_add_elem(char **tab, char *elem)
{
    char **res = malloc(sizeof(char *) * (tab ? my_tab_size(tab) + 2 : 2));
    char *lab = char_to_str(LABEL_CHAR);
    int i = 0;

    if (!res)
        return (tab);
    for (i = 0; tab && tab[i]; ++i) {
        res[i] = my_strdup(tab[i]);
        my_strstr(res[i], lab) ? *my_strstr(res[i], lab) = 0 : 0;
    }
    res[i] = elem ? my_strdup(elem) : NULL;
    res[i] && *my_strstr(res[i], lab) ? *my_strstr(res[i], lab) = 0 : 0;
    res[++i] = NULL;
    strtwt_free_tab(tab);
    free(lab);
    return (res);
}

char **tab_pop_first(char **tab)
{
    char **res = malloc(sizeof(char *) * (my_tab_size(tab) + 1));
    int j = 0;

    if (!tab)
        return (NULL);
    for (int i = 1; i < my_tab_size(tab); ++i)
        res[j++] = my_strdup(tab[i]);
    res[j] = NULL;
    strtwt_free_tab(tab);
    return (res);
}