#include "main.h"

/**
 * shell_get_error - calls error according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int shell_get_error(data_shell *datash, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = shell_env_error(datash);
		break;
	case 126:
		error = denied_path_permission(datash);
		break;
	case 127:
		error = shell_no_err_found(datash);
		break;
	case 2:
		if (shell_strcmp("exit", datash->args[0]) == 0)
			error = shell_exit_error(datash);
		else if (shell_strcmp("cd", datash->args[0]) == 0)
			error = shell_get_cd_err(datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, shell_strlen(error));
		free(error);
	}

	datash->status = eval;
	return (eval);
}
