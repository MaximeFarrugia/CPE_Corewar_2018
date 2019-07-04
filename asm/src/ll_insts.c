/*
** EPITECH PROJECT, 2019
** ll_insts
** File description:
** ll_insts
*/

#include "../../include/my.h"
#include "../../include/asm.h"

int inst_add_node(inst_t **head, char *codesc, char *params)
{
    inst_t *node = malloc(sizeof(inst_t));
    inst_t *tmp = *head;

    if (!node)
        return (84);
    node->code = codesc[0];
    node->desc = codesc[1];
    node->params[0] = params[0];
    node->params[1] = params[1];
    node->params[2] = params[2];
    node->next = NULL;
    if (tmp) {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = node;
    } else
        *head = node;
    return (0);
}

int inst_free(inst_t *head)
{
    if (head) {
        if (head->next)
            inst_free(head->next);
        free(head);
    }
    return (0);
}