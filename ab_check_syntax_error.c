#include "main.h"

/**
 * count_char_repetition - counts char repetitions
 * @input_str: input_str string
 * @i: index_
 * Return: index_ i
 */
int count_char_repetition(char *input_str, int i)
{
	if (*(input_str - 1) == *input_str)
		return (count_char_repetition(input_str - 1, i + 1));

	return (i);
}


/**
 * initial_char - finds index of the first char
 * @input_str: input_str string
 * @i: index
 * Return: 1 if error. 0 otherwise
 */
int initial_char(char *input_str, int *i)
{

	for (*i = 0; input_str[*i]; *i += 1)
	{
		if (input_str[*i] == ' ' || input_str[*i] == '\t')
			continue;

		if (input_str[*i] == ';' || input_str[*i] == '|' || input_str[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * show_syntax_error - Displays syntax error found
 *
 * @shell_dt: data_structure
 * @input_str: input_str string
 * @i: error index
 * @bool: control msg error
 * Return: no return
 */
void show_syntax_error(sh_dt *shell_dt, char *input_str, int i, int bool)
{
	char *info, *msg2, *msg3, *error, *cmd_count;
	int string_length;

	if (input_str[i] == ';')
	{
		if (bool == 0)
			info = (input_str[i + 1] == ';' ? ";;" : ";");
		else
			info = (input_str[i - 1] == ';' ? ";;" : ";");
	}

	if (input_str[i] == '|')
		info = (input_str[i + 1] == '|' ? "||" : "|");

	if (input_str[i] == '&')
		info = (input_str[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax errors: \"";
	msg3 = "\" unexpected error\n";
	cmd_count = convert_int_to_string(shell_dt->cmd_count);
	string_length = str_len(shell_dt->avg[0]) + str_len(cmd_count);
	string_length += str_len(info) + str_len(msg2) + str_len(msg3) + 2;

	error = malloc(sizeof(char) * (string_length + 1));
	if (error == 0)
	{
		free(cmd_count);
		return;
	}
	string_copy(error, shell_dt->avg[0]);
	string_concat(error, ": ");
	string_concat(error, cmd_count);
	string_concat(error, msg2);
	string_concat(error, info);
	string_concat(error, msg3);
	string_concat(error, "\0");

	write(STDERR_FILENO, error, string_length);
	free(error);
	free(cmd_count);
}

/**
 * check_syntax_err - function to intermediate function
 * find and print a syntax error
 *
 * @shell_dt: data structure
 * @input_str: input_str string
 * Return: 1 if error. 0 in other case
 */
int check_syntax_err(sh_dt *shell_dt, char *input_str)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = initial_char(input_str, &begin);
	if (f_char == -1)
	{
		show_syntax_error(shell_dt, input_str, begin, 0);
		return (1);
	}

	i = ab_check_syntax_err1(input_str + begin, 0, *(input_str + begin));
	if (i != 0)
	{
		show_syntax_error(shell_dt, input_str, begin + i, 1);
		return (1);
	}

	return (0);
}
