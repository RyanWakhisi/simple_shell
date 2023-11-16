#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

typedef struct sep_list_s
{
    char separator;
    struct sep_list_s *next;
} sep_list;

typedef struct line_list_s
{
    char *line;
    struct line_list_s *next;
} line_list;

typedef struct data
{
    char **av;
    char *input;
    char **args;
    int status;
    int counter;
    char **_environ;
    char *pid;
} data_shell;

typedef struct r_var_list
{
    int len_var;
    char *val;
    int len_val;
    struct r_var_list *next;
} r_var;

typedef struct builtin_s
{
    char *name;
    int (*f)(data_shell *datash);
} builtin_t;

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
void shell_retrieve_line(char **lineptr, size_t *n, char *buffer, size_t j);
int shell_get_error(data_shell *datash, int eval);
int (*shell_get_builtins(char *cmd))(data_shell *);
void shell_free_data_held(data_shell *datash);
int ab_exit_shell(data_shell *datash);
int ab_exec_line(data_shell *datash);
int shell_current_dir_checker(char *path, int *i);

char *shell_strconcatcat_cd(data_shell *datash, char *msg, char *error, char *ver_str);
char *shell_no_err_found(data_shell *datash);
char *shell_exit_error(data_shell *datash);
char *shell_env_error(data_shell *datash);
char *denied_path_permission(data_shell *datash);
void shell_builtin_env_help(void);
void shell_help_env_set(void);
void unsetenv_shell_help(void);
void help_builtin_general(void);
void shell_help_exit(void);

void shell_aux_help(void);
void shell_help_alias(void);
void shell_help_cd(void);
sep_list *shell_add_node_end(sep_list **head, char sep);
void shell_free_list(sep_list **head);
void shell_free_list_line(line_list **head);
r_var *shell_add_rvar_node(r_var **head, int lvar, char *val, int lval);
void shell_free_list_rvar(r_var **head);
void pointer_memcpy(void *newptr, const void *ptr, unsigned int size);
void *pointer_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int shell_get_len(int n);
char *shell_itoa(int n);
int shell_atoi(char *s);

char *shell_strcat(char *dest, const char *src);
char *shell_strcpy(char *dest, char *src);
int shell_strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
char *shell_strdup(const char *s);
int shell_strlen(const char *s);
int shell_cmp_chars(char str[], const char *delim);
int shell_isdigit(const char *s);

void ab_reverse_string(char *s);
void ab_cd_dot(data_shell *datash);
void ab_cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);
int ab_repeated_char(char *input, int i);
int ab_error_sep_op(char *input, int i, char last);

int ab_first_char(char *input, int *i);
void ab_print_syntax_error(data_shell *datash, char *input, int i, int bool);
int ab_check_error(data_shell *datash, char *input);

int ab_cmp_env_name(const char *nenv, const char *name);
char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);

char *ab_copy_info(char *name, char *value);
void ab_set_env(char *name, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

#endif