/*
** EPITECH PROJECT, 2019
** linked_list
** File description:
** linked_list
*/

#include "../../include/my.h"
#include "../../include/asm.h"

char *char_to_str(char c)
{
    char *res = x_memset(0, 1, sizeof(char));

    res[0] = c;
    return (res);
}

int ll_add_node(ll_t **head, char *line)
{
    ll_t *node = malloc(sizeof(ll_t));
    ll_t *tmp = *head;
    char *sep = char_to_str(SEPARATOR_CHAR);

    if (!node)
        return (84);
    node->line = line ? my_strdup(line) : NULL;
    node->tab = line ? my_str_to_wordtab(node->line,
        (char*[]){ " ", "\t", sep, NULL }) : NULL;
    node->labels = NULL;
    node->next = NULL;
    if (tmp) {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = node;
    } else
        *head = node;
    free(sep);
    return (0);
}

int ll_add_label(ll_t **head, char *label)
{
    ll_t *node = malloc(sizeof(ll_t));
    ll_t *tmp = *head;
    char *sep = char_to_str(SEPARATOR_CHAR);

    if (!node)
        return (84);
    node->line = NULL;
    node->tab = NULL;
    node->labels = tab_add_elem(NULL, label);
    node->next = NULL;
    if (tmp) {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = node;
    } else
        *head = node;
    free(sep);
    return (0);
}

ll_t *ll_delete_node(ll_t **head, ll_t *node)
{
    ll_t *tmp = *head;
    ll_t *temp = NULL;

    if (!head || !(*head) || !node)
        return (NULL);
    while (tmp && tmp != node) {
        temp = tmp;
        tmp = tmp->next;
    }
    if (tmp == *head)
        *head = tmp->next;
    else
        temp->next = tmp->next;
    free(tmp->line);
    strtwt_free_tab(tmp->tab);
    strtwt_free_tab(tmp->labels);
    free(tmp);
    return (*head);
}

int ll_free(ll_t *head)
{
    if (head) {
        if (head->next)
            ll_free(head->next);
        if (head->line)
            free(head->line);
        if (head->tab)
            strtwt_free_tab(head->tab);
        if (head->labels)
            strtwt_free_tab(head->labels);
        free(head);
    }
    return (0);
}