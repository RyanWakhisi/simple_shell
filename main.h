#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

/**
 * struct data - structure with data runtime data
 * @avg: arg vector
 * @input_str: user written command line
 * @argum: argum of the command line
 * @exe_status: last exe_status of the shell
 * @cmd_count: lines cmd_count
 * @s_env: shell environment variable
 * @proc_id: shell process ID
 */
typedef struct data
{
	char **avg;
	char *input_str;
	char **argum;
	int exe_status;
	int cmd_count;
	char **s_env;
	char *proc_id;
} sh_dt;

/**
 * struct separate_lst_s - single linked list
 * @separator_c: ; | &
 * @nxt: nxt node
 * Description: single linked list to store separators
 */
typedef struct separate_lst_s
{
	char separator_c;
	struct separate_lst_s *nxt;
} separate_lst;

/**
 * struct ln_lst_s - singly linked list
 * @line: command line
 * @nxt: nxt node
 * Description: list to store command lines
 */
typedef struct ln_lst_s
{
	char *line;
	struct ln_lst_s *nxt;
} ln_lst;

/**
 * struct rvariable_lst - singly linked list
 * @len_var: variable string_length
 * @val: value of the variable
 * @len_val:  value string_length
 * @nxt: nxt node
 * Description: singly linked list for storing var
 */
typedef struct rvariable_lst
{
	int len_var;
	char *val;
	int len_val;
	struct rvariable_lst *nxt;
} variable_r;

/**
 * struct inbuilt_s - Builtin struct for cmd args.
 * @name: The name of the command builtin
 * @f: pointer function to data type.
 */
typedef struct inbuilt_s
{
	char *name;
	int (*f)(sh_dt *shell_dt);
} inbuilt_t;

separate_lst *append_a_tail_node(separate_lst **lead, char sep);
void free_separate_list(separate_lst **lead);
ln_lst *append_tail_node(ln_lst **lead, char *line);
void free_linked_list(ln_lst **lead);

variable_r *attach_var_after_node(variable_r **lead, int lvar, char *var, int lval);
void clear_var_list(variable_r **lead);

char *string_concat(char *dest, const char *src);
char *string_copy(char *dest, char *src);
int string_compare(char *s1, char *s2);
char *string_locate_chr_pos(char *s, char c);
int string_get_prefix_len(char *s, char *accept);

void copy_into_new_mem(void *new_pointer, const void *ptr, unsigned int size);
void *realloc_memory(void *ptr, unsigned int prev_size, unsigned int new_size);
char **realloc_memory_block(char **ptr, unsigned int prev_size, unsigned int new_size);

char *string_duplicate(const char *s);
int str_len(const char *s);
int str_compare_chars(char str[], const char *dlm);
char *string_strok_c(char str[], const char *dlm);
int check_if_digit(const char *s);

void reverse_string(char *s);

int count_char_repetition(char *input_str, int i);
int ab_check_syntax_err1(char *input_str, int i, char last);
int initial_char(char *input_str, int *i);
void show_syntax_error(sh_dt *shell_dt, char *input_str, int i, int bool);
int check_syntax_err(sh_dt *shell_dt, char *input_str);

char *erase_input_comment(char *in);
void ab_loop_through(sh_dt *shell_dt);

char *read_input_ln(int *i_eof);

char *swap_char(char *input_str, int bool);
void attach_sep_nodes(separate_lst **head_s, ln_lst **head_l, char *input_str);
void go_to_next_cli(separate_lst **list_s, ln_lst **list_l, sh_dt *shell_dt);
int split_cmd_separator(sh_dt *shell_dt, char *input_str);
char **tokenize_input(char *input_str);

void check_input_env(variable_r **h, char *in, sh_dt *data);
int check_input_vars(variable_r **h, char *in, char *st, sh_dt *data);
char *convert_string_mod_input(variable_r **lead, char *input_str, char *new_input, int nlen);
char *invoke_var_replacement(char *input_str, sh_dt *shell_dt);

void assign_var_get_ln(char **lineptr, size_t *n, char *buff, size_t j);
ssize_t ab_shell_get_line(char **lineptr, size_t *n, FILE *strm);

int execute_builtins(sh_dt *shell_dt);

int check_if_current_dir(char *path, int *i);
char *ab_shell_w(char *cmd, char **s_env);
int is_executable_cmd(sh_dt *shell_dt);
int inspect_cmd_error_exists(char *dir, sh_dt *shell_dt);
int execute_cmd_input(sh_dt *shell_dt);

char *ab_shell_extract_env(const char *name, char **s_env);
int display_shell_env(sh_dt *shell_dt);

char *info_cpy_create_alias(char *name, char *value);
void shell_set_environ(char *name, char *value, sh_dt *shell_dt);
int shell_setenv_var(sh_dt *shell_dt);
int ab_shell_unset_env(sh_dt *shell_dt);

void ab_cd_current_dir(sh_dt *shell_dt);
void cd_inputted_dir(sh_dt *shell_dt);
void ab_cd_previous_dir(sh_dt *shell_dt);
void ab_cd_to_dire_home(sh_dt *shell_dt);

int cd_change_curr_dir(sh_dt *shell_dt);

int (*shell_print_cmd_arg(char *cmd))(sh_dt *shell_dt);

int exec_exit_shell(sh_dt *shell_dt);

int get_interger_length(int n);
char *convert_int_to_string(int n);
int convert_string_to_int(char *s);

char *string_concat_cd_err(sh_dt *, char *, char *, char *);
char *ab_obtain_cd_err(sh_dt *shell_dt);
char *ab_err_not_found(sh_dt *shell_dt);
char *ab_err_exit_shell(sh_dt *shell_dt);

char *handle_alias_err(char **argum);
char *ab_handle_err_env(sh_dt *shell_dt);
char *handle_syntax_err(char **argum);
char *handle_permis_err(char **argum);
char *handle_denied_path_err(sh_dt *shell_dt);

int handle_get_builtin_err(sh_dt *shell_dt, int eval);

void handle_interrupt_signal(int sig_handler);

void ab_shell_env_info(void);
void ab_shell_setenv_help(void);
void ab_shell_unsetenv_help(void);
void ab_shell_help_general(void);
void exit_shell_help(void);

void ab_help_shell(void);
void shell_alias_help_builtin(void);
void ab_shell_cd_help(void);
void ab_clear_data(sh_dt *shell_dt);
void ab_set_data(sh_dt *shell_dt, char **avg);

int shell_get_builtin_msg(sh_dt *shell_dt);

#endif
