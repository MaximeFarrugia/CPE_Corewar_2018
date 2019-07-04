/*
** EPITECH PROJECT, 2019
** asm
** File description:
** asm
*/

#ifndef ASM_H_
# define ASM_H_

# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <endian.h>

# define SWAP_BYTES(i) ((i >> (sizeof(i) / 2 * 8)) | (i << (sizeof(i) / 2 * 8)))

typedef struct s_inst {
    char code;
    unsigned char desc;
    char params[3];
    struct s_inst *next;
} inst_t;

typedef struct s_ll {
    char *line;
    char **tab;
    char **labels;
    struct s_ll *next;
} ll_t;

typedef struct s_asm {
    char *filename;
    ll_t *content;
    header_t header;
    inst_t *insts;
} asm_t;

int calculate_label_two(asm_t *casm, int *pos);
int calculate_label(asm_t *casm, ll_t *inst, char *label);
int write_dir(asm_t *casm, ll_t *inst, inst_t *instp, int *fdi);
int write_ind(asm_t *casm, ll_t *inst, int *fdi);
int write_inst(asm_t *casm, ll_t *inst, inst_t *instp, int fd);

int my_getnbr_overflow(char *str);
ll_t *find_next_inst(ll_t *cur);
int tab_contains(char **tab, char *str);
char **tab_add_elem(char **tab, char *elem);
char **tab_pop_first(char **tab);

int param_is_reg(char *param);
int param_is_dir(char *param);
int param_is_ind(char *param);
int param_is_label(char *param, int mode);
int count_inst_params(char **tab, int nbr_args);

int label_exists(asm_t *casm, char *label);
int check_param(ll_t *inst, int inst_idx, int param_idx);
int parse_instruction(asm_t *casm, ll_t *inst, int inst_idx);
int check_instruction(asm_t *casm, ll_t *inst);

int parse_prog_comment(asm_t *casm);
int parse_prog_name(asm_t *casm);

int is_dir_2b(char code);
int calculate_params_bytes(inst_t *inst);
int update_progsize(asm_t *casm);
int asm_parse_header(asm_t *casm);
int asm_parser(asm_t *casm);

int inst_add_node(inst_t **head, char *codesc, char *params);
int inst_free(inst_t *head);

char *char_to_str(char c);
int ll_add_node(ll_t **head, char *line);
int ll_add_label(ll_t **head, char *label);
ll_t *ll_delete_node(ll_t **head, ll_t *node);
int ll_free(ll_t *head);

int remove_labels(asm_t *casm);
char *remove_first_spaces(char *str);
int get_filename(asm_t *casm, char *path);
int get_file_content(asm_t *casm, char *path);
int file_handling(asm_t *casm, char *path);

int init_struct(asm_t *casm);
int my_free_exit(asm_t *casm, int code);

int rint_free(void *ptr);
int display_help(int ac, char **av);

#endif /* !ASM_H_ */