/*
** EPITECH PROJECT, 2019
** header_utils
** File description:
** header_utils
*/

#include "../../include/my.h"
#include "../../include/asm.h"
#include <string.h>

int parse_prog_comment(asm_t *casm)
{
    ll_t *tmp = casm->content;
    int i = 0;
    int j = 0;

    while (tmp) {
        if (!my_strcmp(tmp->tab[0], COMMENT_CMD_STRING))
            break;
        tmp = tmp->next;
    }
    if (!tmp || tmp != casm->content)
        return (tmp ? 84 : 0);
    for (i = 1; tmp->line[i] && tmp->line[i - 1] != '"'; ++i);
    for (; tmp->line[i] && tmp->line[i] != '"'; ++i)
        j < COMMENT_LENGTH ? casm->header.comment[j++] = tmp->line[i] : 0;
    if (!tmp->line[i] || (tmp->line[i + 1] && tmp->line[i + 1] != ' ' &&
        tmp->line[i + 1] != '\t') || j >= COMMENT_LENGTH)
        return (84);
    casm->content = ll_delete_node(&casm->content, tmp);
    return (0);
}

int parse_prog_name(asm_t *casm)
{
    ll_t *tmp = casm->content;
    int i = 0;
    int j = 0;

    if (!tmp)
        return (84);
    if (my_strcmp(tmp->tab[0], NAME_CMD_STRING))
        return (84);
    for (i = 1; tmp->line[i] && tmp->line[i - 1] != '"'; ++i);
    for (; tmp->line[i] && tmp->line[i] != '"'; ++i) {
        if (j >= PROG_NAME_LENGTH)
            return (84);
        casm->header.prog_name[j++] = tmp->line[i];
    }
    if (!tmp->line[i] || (tmp->line[i + 1] && tmp->line[i + 1] != ' ' &&
        tmp->line[i + 1] != '\t'))
        return (84);
    casm->content = ll_delete_node(&casm->content, tmp);
    return (parse_prog_comment(casm));
}