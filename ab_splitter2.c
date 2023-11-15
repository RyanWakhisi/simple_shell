#include "main.h"

/**
 * split_cmd_separator - splits command lines according to separator.
 * @shell_dt: shell's data
 * @input_str: string input
 * Return: 0 on success to exit, else 1 to continue
 */
int split_cmd_separator(sh_dt *shell_dt, char *input_str)
{

	separate_lst *head_s, *list_s;
	ln_lst *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	attach_sep_nodes(&head_s, &head_l, input_str);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		shell_dt->input_str = list_l->line;
		shell_dt->argum = tokenize_input(shell_dt->input_str);
		loop = execute_builtins(shell_dt);
		free(shell_dt->argum);

		if (loop == 0)
			break;

		go_to_next_cli(&list_s, &list_l, shell_dt);

		if (list_l != NULL)
			list_l = list_l->nxt;
	}

	free_separate_list(&head_s);
	free_linked_list(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}
/**
 * tokenize_input - tokenizes the string input
 * @input_str: input string
 * Return: splitted string
 */
char **tokenize_input(char *input_str)
{
	size_t bsize;
	size_t i;
	char **tokens;
	char *token;

	bsize = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": error in allocation\n", 18);
		exit(EXIT_FAILURE);
	}

	token = string_strok_c(input_str, TOK_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOK_BUFSIZE;
			tokens = realloc_memory_block(tokens, i, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": error in allaction\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = string_strok_c(NULL, TOK_DELIM);
		tokens[i] = token;
	}

	return (tokens);
}
