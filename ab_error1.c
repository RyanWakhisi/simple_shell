#include "main.h"

/**
 * string_concat_cd_err - function that concatenates cd error info
 * @shell_dt: shell's data
 * @info: information to display
 * @error: error information
 * @string_ver: counter for string.
 * Return: error information
 */
char *string_concat_cd_err(sh_dt *shell_dt, char *info, char *error, char *string_ver)
{
	char *invalid_flag;

	string_copy(error, shell_dt->avg[0]);
	string_concat(error, ": ");
	string_concat(error, string_ver);
	string_concat(error, ": ");
	string_concat(error, shell_dt->argum[0]);
	string_concat(error, info);
	if (shell_dt->argum[1][0] == '-')
	{
		invalid_flag = malloc(3);
		invalid_flag[0] = '-';
		invalid_flag[1] = shell_dt->argum[1][1];
		invalid_flag[2] = '\0';
		string_concat(error, invalid_flag);
		free(invalid_flag);
	}
	else
	{
		string_concat(error, shell_dt->argum[1]);
	}

	string_concat(error, "\n");
	string_concat(error, "\0");
	return (error);
}

/**
 * ab_obtain_cd_err - obtain error information for cd.
 * @shell_dt: shell's data
 * Return: Error information
 */
char *ab_obtain_cd_err(sh_dt *shell_dt)
{
	int string_length, len_id;
	char *error, *string_ver, *info;

	string_ver = convert_int_to_string(shell_dt->cmd_count);
	if (shell_dt->argum[1][0] == '-')
	{
		info = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		info = ": can't cd to ";
		len_id = str_len(shell_dt->argum[1]);
	}

	string_length = str_len(shell_dt->avg[0]) + str_len(shell_dt->argum[0]);
	string_length += str_len(string_ver) + str_len(info) + len_id + 5;
	error = malloc(sizeof(char) * (string_length + 1));

	if (error == 0)
	{
		free(string_ver);
		return (NULL);
	}
	error = string_concat_cd_err(shell_dt, info, error, string_ver);
	free(string_ver);
	return (error);
}

/**
 * ab_err_not_found - Information for no error
 * @shell_dt: shell's data
 * Return: Error information
 */
char *ab_err_not_found(sh_dt *shell_dt)
{
	int string_length;
	char *error;
	char *string_ver;

	string_ver = convert_int_to_string(shell_dt->cmd_count);
	string_length = str_len(shell_dt->avg[0]) + str_len(string_ver);
	string_length += str_len(shell_dt->argum[0]) + 16;
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
	string_concat(error, ": unavailable\n");
	string_concat(error, "\0");
	free(string_ver);
	return (error);
}


