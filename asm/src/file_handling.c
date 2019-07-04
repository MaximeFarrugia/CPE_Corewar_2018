/*
** EPITECH PROJECT, 2019
** file_handling
** File description:
** file_handling
*/

#include "../../include/my.h"
#include "../../include/asm.h"

int remove_labels(asm_t *casm)
{
    ll_t *tmp = casm->content;
    ll_t *next_inst = NULL;

    while (tmp) {
        if (tmp->tab && param_is_label(tmp->tab[0], 0) == 1 && !tmp->tab[1]) {
            next_inst = find_next_inst(tmp);
            next_inst ? next_inst->labels =
                tab_add_elem(next_inst->labels, tmp->tab[0]) : 0;
            !next_inst ? ll_add_label(&casm->content, tmp->tab[0]) : 0;
            tmp = ll_delete_node(&casm->content, tmp);
        } else if (tmp->tab &&
            param_is_label(tmp->tab[0], 0) == 1 && tmp->tab[1]) {
            tmp->labels = tab_add_elem(tmp->labels, tmp->tab[0]);
            tmp->tab = tab_pop_first(tmp->tab);
        }
        tmp ? tmp = tmp->next : 0;
    }
    return (0);
}

char *remove_first_spaces(char *str)
{
    char *res = x_memset(0, my_strlen(str) + 1, sizeof(char));
    int i = -1;
    int j = 0;

    if (!res)
        return (NULL);
    while (str[++i] && (str[i] == ' ' || str[i] == '\t'));
    while (str[i])
        res[j++] = str[i++];
    free(str);
    return (res);
}

int get_filename(asm_t *casm, char *path)
{
    char *slash = NULL;

    if (!(casm->filename = my_strdup(path)))
        return (84);
    my_revstr(casm->filename);
    if ((slash = my_strstr(casm->filename, "/")))
        *slash = 0;
    if (!my_strncmp(casm->filename, "s.", 2)) {
        my_revstr(casm->filename);
        casm->filename[my_strlen(casm->filename) - 1] = 0;
        casm->filename[my_strlen(casm->filename) - 1] = 0;
    } else
        my_revstr(casm->filename);
    casm->filename = my_realloc(casm->filename, my_strlen(casm->filename) + 4);
    my_strcat(casm->filename, ".cor");
    return (0);
}

int get_file_content(asm_t *casm, char *path)
{
    int fd = open(path, O_RDONLY);
    char *s = NULL;
    char *com = char_to_str(COMMENT_CHAR);

    if (fd == -1)
        return (84);
    while ((s = get_next_line(fd))) {
        s = remove_first_spaces(s);
        if (my_strstr(s, com))
            *my_strstr(s, com) = 0;
        if (*s && *s != COMMENT_CHAR && ll_add_node(&casm->content, s) == 84) {
            free(s);
            free(com);
            return (84);
        }
        free(s);
    }
    free(com);
    remove_labels(casm);
    return (0);
}

int file_handling(asm_t *casm, char *path)
{
    if (get_filename(casm, path) == 84)
        return (84);
    if (get_file_content(casm, path))
        return (84);
    if (asm_parser(casm) == 84)
        return (84);
    return (0);
}