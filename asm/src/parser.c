/*
** EPITECH PROJECT, 2019
** parser
** File description:
** parser
*/

#include "../../include/my.h"
#include "../../include/asm.h"

int is_dir_2b(char code)
{
    char codes[6] = { 0x09, 0x0a, 0x0b, 0x0c, 0x0e, 0x0f };

    for (int i = 0; i < 6; ++i) {
        if (code == codes[i])
            return (2);
    }
    return (DIR_SIZE);
}

int calculate_params_bytes(inst_t *inst)
{
    int count = 0;

    count += inst->params[0] == T_REG ? 1 : 0;
    count += inst->params[0] == T_DIR ? is_dir_2b(inst->code) : 0;
    count += inst->params[0] == T_IND - 1 ? IND_SIZE : 0;
    count += inst->params[1] == T_REG ? 1 : 0;
    count += inst->params[1] == T_DIR ? is_dir_2b(inst->code) : 0;
    count += inst->params[1] == T_IND - 1 ? IND_SIZE : 0;
    count += inst->params[2] == T_REG ? 1 : 0;
    count += inst->params[2] == T_DIR ? is_dir_2b(inst->code) : 0;
    count += inst->params[2] == T_IND - 1 ? IND_SIZE : 0;
    count += inst->desc ? 2 : 1;
    return (count);
}

int update_progsize(asm_t *casm)
{
    inst_t *tmp = casm->insts;

    while (tmp) {
        casm->header.prog_size += calculate_params_bytes(tmp);
        tmp = tmp->next;
    }
    casm->header.prog_size = be32toh(casm->header.prog_size);
    return (0);
}

int asm_parse_header(asm_t *casm)
{
    my_memset(&casm->header, 0, sizeof(header_t));
    casm->header.magic = be32toh(COREWAR_EXEC_MAGIC);
    casm->header.prog_size = 0;
    if (parse_prog_name(casm) == 84)
        return (84);
    return (0);
}

int asm_parser(asm_t *casm)
{
    int fd = 0;
    ll_t *tmp = casm->content;
    inst_t *inst = casm->insts;

    if (asm_parse_header(casm) == 84)
        return (84);
    for (ll_t *tmp = casm->content; tmp; tmp = tmp->next) {
        if (check_instruction(casm, tmp) == 84)
            return (84);
    }
    update_progsize(casm);
    fd = open(casm->filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    write(fd, &casm->header, sizeof(casm->header));
    for (tmp = casm->content, inst = casm->insts; tmp && inst;
        tmp = tmp->next, inst = inst->next)
        write_inst(casm, tmp, inst, fd);
    close(fd);
    return (0);
}