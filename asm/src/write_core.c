/*
** EPITECH PROJECT, 2019
** write_core
** File description:
** write_core
*/

#include "../../include/my.h"
#include "../../include/asm.h"

int calculate_label_two(asm_t *casm, int *pos)
{
    int neg = pos[0] < pos[1] ? 1 : 0;
    inst_t *tmp = casm->insts;
    int count = 0;

    if (!neg) {
        pos[0] ^= pos[1];
        pos[1] ^= pos[0];
        pos[0] ^= pos[1];
    }
    for (int i = 0; tmp && i < pos[0]; ++i, tmp = tmp->next);
    for (int i = pos[0]; tmp && i < pos[1]; ++i, tmp = tmp->next)
        count += calculate_params_bytes(tmp);
    return (neg ? count * -1 : count);
}

int calculate_label(asm_t *casm, ll_t *inst, char *label)
{
    int pos[2] = { 0, 0 };
    int count = 0;
    char *dir = char_to_str(DIRECT_CHAR);
    char *lab = char_to_str(LABEL_CHAR);
    char *s = strtwt_epur_str(label, (char*[]){ dir, lab, NULL }, 0);

    if (inst->labels && tab_contains(inst->labels, s))
        return (rint_free(dir) | rint_free(lab) | rint_free(s) | 0);
    for (ll_t *tmp = casm->content; tmp; tmp = tmp->next, ++pos[0]) {
        if (tmp->labels && tab_contains(tmp->labels, s))
            break;
    }
    for (ll_t *tmp = casm->content; tmp; tmp = tmp->next, ++pos[1]) {
        if (tmp == inst)
            break;
    }
    count = calculate_label_two(casm, pos);
    return (rint_free(dir) | rint_free(lab) | rint_free(s) | count);
}

int write_dir(asm_t *casm, ll_t *inst, inst_t *instp, int *fdi)
{
    int tmp = 0;

    if (param_is_label(&inst->tab[fdi[1] + 1][1], 1) == 1)
        tmp = calculate_label(casm, inst, inst->tab[fdi[1] + 1]);
    else
        tmp = my_getnbr_overflow(&inst->tab[fdi[1] + 1][1]);
    tmp = be32toh(tmp);
    if (is_dir_2b(instp->code) != DIR_SIZE)
        tmp = SWAP_BYTES(tmp);
    write(fdi[0], &tmp, is_dir_2b(instp->code));
    return (0);
}

int write_ind(asm_t *casm, ll_t *inst, int *fdi)
{
    int tmp = 0;

    if (param_is_label(inst->tab[fdi[1] + 1], 1) == 1)
        tmp = calculate_label(casm, inst, inst->tab[fdi[1] + 1]);
    else
        tmp = my_getnbr_overflow(inst->tab[fdi[1] + 1]);
    tmp = be32toh(tmp);
    tmp = SWAP_BYTES(tmp);
    write(fdi[0], &tmp, IND_SIZE);
    return (0);
}

int write_inst(asm_t *casm, ll_t *inst, inst_t *instp, int fd)
{
    int reg = 0;

    write(fd, &instp->code, 1);
    if (instp->desc)
        write(fd, &instp->desc, 1);
    for (int i = 0; i < 3; ++i) {
        if (instp->params[i] && instp->params[i] == T_REG) {
            reg = my_getnbr_overflow(&inst->tab[i + 1][1]);
            write(fd, &reg, 1);
        } else if (instp->params[i] && instp->params[i] == T_DIR) {
            write_dir(casm, inst, instp, (int[]){ fd, i });
        } else {
            instp->params[i] ? write_ind(casm, inst, (int[]){ fd, i }) : 0;
        }
    }
    return (0);
}