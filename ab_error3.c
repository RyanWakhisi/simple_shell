#include "main.h"

/**
 * ab_err_exit_shell - error information for exit
 * @shell_dt: shell's data
 * Return: Error information
 */
char *ab_err_exit_shell(sh_dt *shell_dt)
{
	int string_length;
	char *error;
	char *string_ver;

	string_ver = convert_int_to_string(shell_dt->cmd_count);
	string_length = str_len(shell_dt->avg[0]) + str_len(string_ver);
	string_length += str_len(shell_dt->argum[0]) + str_len(shell_dt->argum[1]) + 23;
	error = malloc(sizeof(char) * (string_length + 1));
	if (error == 0)
	{
		free(string_ver);
		return (NULL);
	}
	string_copy(error, shell_dt->avg[0]);
	string_concat(error, ": ");
	string_concat(error, string_ver);
	string_concat(error, ": ");
	string_concat(error, shell_dt->argum[0]);
	string_concat(error, ": Num not allowed: ");
	string_concat(error, shell_dt->argum[1]);
	string_concat(error, "\n\0");
	free(string_ver);
	return (error);
}