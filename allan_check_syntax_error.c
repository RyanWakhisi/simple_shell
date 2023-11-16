#include "main.h"

/**
 * ab_repeated_char - counts the repetitions of a char
 *
 * @input: input string
 * @i: index
 * Return: repetitions
 */
int ab_repeated_char(char *input, int i)
{
	if (*(input - 1) == *input)
		return (ab_repeated_char(input - 1, i + 1));

	return (i);
}

/**
 * ab_error_sep_op - finds syntax errors
 *
 * @input: input string
 * @i: index
 * @last: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int ab_error_sep_op(char *input, int i, char last)
{
	int count;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (ab_error_sep_op(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			count = ab_repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			count = ab_repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (ab_error_sep_op(input + 1, i + 1, *input));
}

/**
 * ab_first_char - finds index of the first char
 *
 * @input: input string
 * @i: index
 * Return: 1 if there is an error. 0 in other case.
 */
int ab_first_char(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * ab_print_syntax_error - prints when a syntax error is found
 *
 * @datash: data structure
 * @input: input string
 * @i: index of the error
 * @bool: to control msg error
 * Return: no return
 */
void ab_print_syntax_error(data_shell *datash, char *input, int i, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = shell_itoa(datash->counter);
	length = shell_strlen(datash->av[0]) + shell_strlen(counter);
	length += shell_strlen(msg) + shell_strlen(msg2) + shell_strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	shell_strcpy(error, datash->av[0]);
	shell_strcat(error, ": ");
	shell_strcat(error, counter);
	shell_strcat(error, msg2);
	shell_strcat(error, msg);
	shell_strcat(error, msg3);
	shell_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * ab_check_error - intermediate function to
 * find and print a syntax error
 *
 * @datash: data structure
 * @input: input string
 * Return: 1 if there is an error. 0 in other case
 */
int ab_check_error(data_shell *datash, char *input)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = ab_first_char(input, &begin);
	if (f_char == -1)
	{
		ab_print_syntax_error(datash, input, begin, 0);
		return (1);
	}

	i = ab_error_sep_op(input + begin, 0, *(input + begin));
	if (i != 0)
	{
		ab_print_syntax_error(datash, input, begin + i, 1);
		return (1);
	}

	return (0);
}
