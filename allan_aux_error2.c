#include "main.h"

/**
 * shell_env_error - error message for env in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: error message.
 */
char *shell_env_error(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = shell_itoa(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	length = shell_strlen(datash->av[0]) + shell_strlen(ver_str);
	length += shell_strlen(datash->args[0]) + shell_strlen(msg) + 4;
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
	shell_strcat(error, msg);
	shell_strcat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * denied_path_persmission - error message for path and failure denied permission.
 * @datash: data relevant (counter, arguments).
 *
 * Return: The error string.
 */
char *denied_path_persmission(data_shell *datash)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = shell_itoa(datash->counter);
	length = shell_strlen(datash->av[0]) + shell_strlen(ver_str);
	length += shell_strlen(datash->args[0]) + 24;
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
	shell_strcat(error, ": Permission denied\n");
	shell_strcat(error, "\0");
	free(ver_str);
	return (error);
}
