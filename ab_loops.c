#include "main.h"

/**
 * erase_input_comment - This erases comments for input
 * @in: The input string
 * Return: The input string with no comments
 */
char *erase_input_comment(char *in)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		in = realloc_memory(in, i, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}
/**
 * ab_loop_through - shell's loop
 * @shell_dt: shell's data
 * Return: Nothing
 */
void ab_loop_through(sh_dt *shell_dt)
{
	int loop, i_eof;
	char *input_str;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input_str = read_input_ln(&i_eof);
		if (i_eof != -1)
		{
			input_str = erase_input_comment(input_str);
			if (input_str == NULL)
				continue;

			if (check_syntax_err(shell_dt, input_str) == 1)
			{
				shell_dt->exe_status = 2;
				free(input_str);
				continue;
			}
			input_str = invoke_var_replacement(input_str, shell_dt);
			loop = split_cmd_separator(shell_dt, input_str);
			shell_dt->cmd_count += 1;
			free(input_str);
		}
		else
		{
			loop = 0;
			free(input_str);
		}
	}
}
