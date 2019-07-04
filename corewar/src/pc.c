/*
** EPITECH PROJECT, 2019
** pc
** File description:
** pc
*/

#include "../../include/my.h"
#include "../../include/vm.h"

int fill_pc(pc_t *node, int pc, int *reg, pc_t *parent)
{
    node->pc = pc;
    node->cycle_wait = 0;
    node->opcode = 0;
    node->carry = parent ? parent->carry : 0;
    for (int i = 0; i < REG_NUMBER; ++i)
        node->reg[i] = parent ? parent->reg[i] : reg[i];
    node->next = NULL;
    return (0);
}

int add_pc(pc_t **head, int pc, int *reg, void *parent)
{
    pc_t *node = malloc(sizeof(pc_t));
    pc_t *tmp = *head;

    if (!node)
        return (84);
    fill_pc(node, pc, reg, tmp ? parent : NULL);
    node->p = tmp ? (champ_t *)((pc_t *)parent)->p : (champ_t*)parent;
    if (tmp) {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = node;
    } else
        *head = node;
    return (0);
}

int pc_free(pc_t *head)
{
    if (head) {
        if (head->next)
            pc_free(head->next);
        free(head);
    }
    return (0);
}