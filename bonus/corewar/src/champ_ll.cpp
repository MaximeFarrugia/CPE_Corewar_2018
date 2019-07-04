/*
** EPITECH PROJECT, 2019
** champ_ll
** File description:
** champ_ll
*/

#include "../../include/vm.hpp"

int champ_fill_node(champ_t *node, int nb, int address)
{
    node->nb = nb;
    node->reg[0] = nb;
    for (int i = 1; i < REG_NUMBER; ++i)
        node->reg[i] = 0;
    node->pc = NULL;
    if (add_pc(&node->pc, address, node->reg, node) == 84)
        return (rint_free(node->name) | 84);
    node->last_live = 0;
    node->dead = 0;
    node->total_lives = 0;
    node->next = NULL;
    return (0);
}

int champ_add_node(champ_t **head, int nb, char *name, int address)
{
    champ_t *node = (champ_t *)malloc(sizeof(champ_t));
    champ_t *tmp = *head;

    if (!node || !(node->name = strdup(name)))
        return (rint_free(node) | (node ? rint_free(node->name) : 0) | 84);
    if (champ_fill_node(node, nb, address) == 84)
        return (rint_free(node) | 84);
    if (tmp) {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = node;
    } else
        *head = node;
    return (0);
}

int champ_free(champ_t *head)
{
    if (head) {
        if (head->next)
            champ_free(head->next);
        if (head->name)
            free(head->name);
        if (head->pc)
            pc_free(head->pc);
        free(head);
    }
    return (0);
}