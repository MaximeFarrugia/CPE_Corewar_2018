/*
** EPITECH PROJECT, 2019
** vm
** File description:
** vm
*/

#ifndef VM_H_
# define VM_H_

# include "./op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <ncurses.h>

# define SIZE_MAX_CHAMPION MEM_SIZE / 4
# define NEG(i) (i < 0 ? MEM_SIZE + i : i)

# define COLOR_GRAY 100

typedef struct s_pc pc_t;
typedef struct s_champ champ_t;

struct s_pc {
    int reg[REG_NUMBER];
    int pc;
    int cycle_wait;
    char opcode;
    int carry;
    champ_t *p;
    struct s_pc *next;
};

struct s_champ {
    int reg[REG_NUMBER];
    char *name;
    int nb;
    pc_t *pc;
    int last_live;
    int dead;
    int total_lives;
    struct s_champ *next;
};

typedef struct s_vector2i {
    int x;
    int y;
} vector2i_t;

typedef struct s_vm {
    int dump;
    unsigned char board[MEM_SIZE];
    unsigned char gboard[MEM_SIZE];
    champ_t *champs;
    header_t header;
    int cycle_to_die;
    int cycle;
    int lives;
    int graphic;
    int last_live;
    WINDOW *wins[6];
    int running;
    char **bytes;
} vm_t;

/* cwncurses */
/* menu_display.c */
int display_title_two(WINDOW *title, int x, int y);
int display_title(void);
int display_button(void);
/* menu_utils.c */
int init_all_pair(void);
int my_strlen_tab(char **tab);
int get_bytes(vm_t *ft);
int free_array(char **tab);
/* menu.c */
int print_all_random(vm_t *ft, int *count, int tab, int y);
int print_menu(vm_t *ft);
int menu(vm_t *ft);
/* end_ncurses.c */
int cw_get_winner(vm_t *vm);
int end_player(vm_t *vm, int widx, int win);
int end_ncurses(vm_t *vm, int force);
/* utils.c */
int champ_processes(champ_t *champ);
int total_processes(vm_t *vm);
champ_t *get_champ_by_nb(vm_t *vm, int nb);
/* info_windows.c */
int update_infos(vm_t *vm, int tpos);
int update_pone(vm_t *vm);
int update_ptwo(vm_t *vm);
int update_pthree(vm_t *vm);
int update_pfour(vm_t *vm);
/* print_arena.c */
int cw_print_arena(vm_t *vm);
/* update_ncurses.c */
int dctxt(WINDOW *win, vector2i_t pos, char *str, int pair);
int dcnbr(WINDOW *win, vector2i_t pos, int nbr, int pair);
int clean_window(WINDOW *win);
int update_windows(vm_t *vm);
int update_ncurses(vm_t *vm);
/* init_ncurses.c */
int init_colors(void);
int init_ncurses(vm_t *vm);

/* pc.c */
int fill_pc(pc_t *node, int pc, int *reg, pc_t *parent);
int add_pc(pc_t **head, int pc, int *reg, void *parent);
int pc_free(pc_t *head);

/* champ_ll.c */
int champ_add_node(champ_t **head, int nb, char *name, int address);
int champ_free(champ_t *head);

/* utils.c */
int rint_free(void *ptr);
int tab_contains(char **tab, char *str);

/* struct.h */
int init_struct(vm_t *vm);
int my_free_exit(vm_t *vm, int code);

/* usage.c */
void usage(char *name);

/* error_handling_parameter.c */
int check_n(int ac, char **av);
int is_n(char **av, int *i, int *nb_a, int *nb_n);
int check_same_numbers(int ac, char **av);
int add_in_save(int nb);
int unused_after(int nb, int ac, char **av, int index);

/* print_arena.c */
int my_int_size(int nbr);
int print_line_number(int index, int ctw);
int print_arena(vm_t *vm);

/* create_champ.c */
int check_magic(vm_t *vm, int fd);
int check_address(vm_t *vm, int address);
int put_champ_in_board(vm_t *vm, int fd, int address, int number);
int create_champ(vm_t *vm, int number, int address, char *file);

/* get_parameter.c */
int get_nb_champ(int ac, char **av);
int change_param(char **param, vm_t *vm, int *address, int *number);
int new_number(int number, int ac, char **av, int index);
int new_address(int nb_champ, vm_t *vm);
int create_list(int ac, char **av, vm_t *vm);

/* get_opcodes.c */
int get_opcode(vm_t *vm, int pc);
int update_cycle_wait(int opcode, int cycle_wait);
int get_opcodes(vm_t *vm);

/* fcts */
/* get_parameters.c */
int param_to_int(vm_t *vm, int pc, int size);
int calculate_params_bytes(int *params, int index);
int get_params_values(vm_t *vm, int pc, int *params, int index);
int get_optab_idx(char code);
int get_parameters(vm_t *vm, pc_t *pc, int *params, int index);
/* write_in_mem.c */
int write_in_mem(vm_t *vm, int pc, int data, int size);
/* others */
int cwlive(vm_t *vm, pc_t *pc);
int cwld(vm_t *vm, pc_t *pc);
int cwst(vm_t *vm, pc_t *pc);
int cwadd(vm_t *vm, pc_t *pc);
int cwsub(vm_t *vm, pc_t *pc);
int cwand(vm_t *vm, pc_t *pc);
int cwor(vm_t *vm, pc_t *pc);
int cwxor(vm_t *vm, pc_t *pc);
int cwzjmp(vm_t *vm, pc_t *pc);
int cwldi(vm_t *vm, pc_t *pc);
int cwsti(vm_t *vm, pc_t *pc);
int cwfork(vm_t *vm, pc_t *pc);
int cwlld(vm_t *vm, pc_t *pc);
int cwlldi(vm_t *vm, pc_t *pc);
int cwlfork(vm_t *vm, pc_t *pc);
int cwaff(vm_t *vm, pc_t *pc);

/* exec_opcodes.c */
int exec_opcode(vm_t *vm, pc_t *pc);
int check_death(vm_t *vm);
int exec_opcodes(vm_t *vm);

/* vm.c */
int is_game_over(vm_t *vm);
int check_death(vm_t *vm);
int get_winner(vm_t *vm);
int virtual_machine(vm_t *vm);

#endif /* !VM_H_ */