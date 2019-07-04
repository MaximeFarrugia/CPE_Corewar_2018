/*
** EPITECH PROJECT, 2019
** instruction_utils
** File description:
** instruction_utils
*/

#include "../../include/my.h"
#include "../../include/asm.h"

int label_exists(asm_t *casm, char *label)
{
    ll_t *tmp = casm->content;
    char *dir = char_to_str(DIRECT_CHAR);
    char *lab = char_to_str(LABEL_CHAR);
    char *s = strtwt_epur_str(label, (char*[]){ dir, lab, NULL }, 0);
    int skip = 0;

    if (!my_strstr(label, lab))
        skip = 1;
    while (!skip && tmp) {
        if (tab_contains(tmp->labels, s))
            break;
        tmp = tmp->next;
    }
    free(s);
    return ((rint_free(dir) | rint_free(lab)) | (tmp || skip ? 1 : -1));
}

int check_param(ll_t *inst, int inst_idx, int param_idx)
{
    if (param_is_reg(inst->tab[param_idx]) == 1 &&
        !(op_tab[inst_idx].type[param_idx - 1] & T_REG))
        return (84);
    else if (param_is_reg(inst->tab[param_idx]) == 1)
        return (T_REG);
    if (param_is_dir(inst->tab[param_idx]) == 1 &&
        !(op_tab[inst_idx].type[param_idx - 1] & T_DIR))
        return (84);
    else if (param_is_dir(inst->tab[param_idx]) == 1)
        return (T_DIR);
    if (param_is_ind(inst->tab[param_idx]) == 1 &&
        !(op_tab[inst_idx].type[param_idx - 1] & T_IND))
        return (84);
    else if (param_is_ind(inst->tab[param_idx]) == 1)
        return (T_IND);
    return (84);
}

int parse_instruction(asm_t *casm, ll_t *inst, int inst_idx)
{
    char codesc[2] = { 0, 0 };
    char params[3] = { 0, 0, 0 };
    char *no_desc[] = { "live", "zjmp", "fork", "lfork" };

    for (int i = 0; inst->tab[i]; ++i) {
        !i ? codesc[0] = op_tab[inst_idx].code : 0;
        if (i && ((params[i - 1] = check_param(inst, inst_idx, i)) == 84 ||
            label_exists(casm, inst->tab[i]) == -1))
            return (84);
        if (i && params[i - 1] == T_IND)
            params[i - 1] -= 1;
    }
    for (int i = 0; i < 3; ++i)
        codesc[1] |= (params[i] << (2 * (3 - i)));
    for (int i = 0; i < 4; ++i) {
        if (!my_strcmp(op_tab[inst_idx].mnemonique, no_desc[i]))
            codesc[1] = 0;
    }
    inst_add_node(&casm->insts, codesc, params);
    return (0);
}

int check_instruction(asm_t *casm, ll_t *inst)
{
    int i = 0;

    if (!inst->tab)
        return (0);
    for (i = 0; op_tab[i].mnemonique; ++i) {
        if (!my_strcmp(inst->tab[0], op_tab[i].mnemonique))
            break;
    }
    if (!op_tab[i].mnemonique ||
        count_inst_params(inst->tab, op_tab[i].nbr_args) == -1)
        return (84);
    if (parse_instruction(casm, inst, i) == 84)
        return (84);
    return (0);
}