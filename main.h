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

char *shell_char_swap(char *input, int bool);
void shell_add_node_sep(sep_list **head_s, line_list **head_l, char *input);
void shell_next_cmd(sep_list **list_s, line_list **list_l, data_shell *datash);
int shell_cmd_split(data_shell *datash, char *input);
char **shell_split_line(char *input);
void shell_set_struct_data(data_shell *datash, char **av);
void shell_envir_checker(r_var **h, char *in, data_shell *data);
int shell_var_checker(r_var **h, char *in, char *st, data_shell *data);
char *shell_new_input(r_var **head, char *input, char *new_input, int nlen);
char *shell_var_rep(char *input, data_shell *datash);
char *shell_line_reader(int *i_eof);
char *shell_no_arguments(char *in);
void shell_loop_through_data(data_shell *datash);
void shell_get_sigint(int sig);
void shell_retrive_line(char **lineptr, size_t *n, char *buffer, size_t j);
int shell_get_error(data_shell *datash, int eval);
int (*shell_get_builtins(char *cmd))(data_shell *);
void shell_free_data_held(data_shell *datash);
int ab_exit_shell(data_shell *datash);
int ab_exec_line(data_shell *datash);
int shell_current_dir_checker(char *path, int *i);
#endif
