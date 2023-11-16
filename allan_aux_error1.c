#include "main.h"

/**
 * shell_strconcatcat_cd - function that concatenates the message for cd error
 *
 * @datash: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */
char *shell_strconcatcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	shell_strcpy(error, datash->av[0]);
	shell_strcat(error, ": ");
	shell_strcat(error, ver_str);
	shell_strcat(error, ": ");
	shell_strcat(error, datash->args[0]);
	shell_strcat(error, msg);
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		shell_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		shell_strcat(error, datash->args[1]);
	}

	shell_strcat(error, "\n");
	shell_strcat(error, "\0");
	return (error);
}

/**
 * shell_get_cd_err - error message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */
char *shell_get_cd_err(data_shell *datash)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = shell_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = shell_strlen(datash->args[1]);
	}

	length = shell_strlen(datash->av[0]) + shell_strlen(datash->args[0]);
	length += shell_strlen(ver_str) + shell_strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = shell_strconcatcat_cd(datash, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * shell_no_err_found - generic error message for command not found
 * @datash: data relevant (counter, arguments)
 * Return: Error message
 */
char *shell_no_err_found(data_shell *datash);
{
	int length;
	char *error;
	char *ver_str;

	ver_str = shell_itoa(datash->counter);
	length = shell_strlen(datash->av[0]) + shell_strlen(ver_str);
	length += shell_strlen(datash->args[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	shell_strcpy(error, datash->av[0]);
	shell_strcat(error, ": ");
	shell_strcat(error, ver_str);
	shell_strcat(error, ": ");
	shell_strcat(error, datash->args[0]);
	shell_strcat(error, ": not found\n");
	shell_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * shell_exit_error - generic error message for exit in get_exit
 * @datash: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *shell_exit_error(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = shell_itoa(datash->counter);
	length = shell_strlen(datash->av[0]) + shell_strlen(ver_str);
	length += shell_strlen(datash->args[0]) + shell_strlen(datash->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	shell_strcpy(error, datash->av[0]);
	shell_strcat(error, ": ");
	shell_strcat(error, ver_str);
	shell_strcat(error, ": ");
	shell_strcat(error, datash->args[0]);
	shell_strcat(error, ": Illegal number: ");
	shell_strcat(error, datash->args[1]);
	shell_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}
