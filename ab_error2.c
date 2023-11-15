#include "main.h"
/**
 * ab_handle_err_env - The function handle's error info for envronment.
 * @shell_dt: shell's data
 * Return: An error info
 */
char *ab_handle_err_env(sh_dt *shell_dt)
{
	int string_length;
	char *error;
	char *info;
	char *string_ver;

	string_ver = convert_int_to_string(shell_dt->cmd_count);
	info = ": Not in a position to modify environment\n";
	string_length = str_len(shell_dt->avg[0]) + str_len(string_ver);
	string_length += str_len(shell_dt->argum[0]) + str_len(info) + 4;
	error = malloc(sizeof(char) * (string_length + 1));
	if (error == 0)
	{
		free(error);
		free(string_ver);
		return (NULL);
	}
	string_copy(error, shell_dt->avg[0]);
	string_concat(error, ": ");
	string_concat(error, string_ver);
	string_concat(error, ": ");
	string_concat(error, shell_dt->argum[0]);
	string_concat(error, info);
	string_concat(error, "\0");
	free(string_ver);
	return (error);
}
/**
 * handle_denied_path_err - handles error for denied permission in path
 * @shell_dt: shell's data
 * Return: error information
 */
char *handle_denied_path_err(sh_dt *shell_dt)
{
	int string_length;
	char *string_ver;
	char *error;

	string_ver = convert_int_to_string(shell_dt->cmd_count);
	string_length = str_len(shell_dt->avg[0]) + str_len(string_ver);
	string_length += str_len(shell_dt->argum[0]) + 24;
	error = malloc(sizeof(char) * (string_length + 1));
	if (error == 0)
	{
		free(error);
		free(string_ver);
		return (NULL);
	}
	string_copy(error, shell_dt->avg[0]);
	string_concat(error, ": ");
	string_concat(error, string_ver);
	string_concat(error, ": ");
	string_concat(error, shell_dt->argum[0]);
	string_concat(error, ": Access denied\n");
	string_concat(error, "\0");
	free(string_ver);
	return (error);
}
