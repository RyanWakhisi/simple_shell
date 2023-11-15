#include "main.h"

/**
 * handle_get_builtin_err - A function that calls the builtin error commands
 * @shell_dt: data struct that contains args
 * @eval: value of error
 * Return: error
 */
int handle_get_builtin_err(sh_dt *shell_dt, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = ab_handle_err_env(shell_dt);
		break;
	case 126:
		error = handle_denied_path_err(shell_dt);
		break;
	case 127:
		error = ab_err_not_found(shell_dt);
		break;
	case 2:
		if (string_compare("exit", shell_dt->argum[0]) == 0)
			error = ab_err_exit_shell(shell_dt);
		else if (string_compare("cd", shell_dt->argum[0]) == 0)
			error = ab_obtain_cd_err(shell_dt);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, str_len(error));
		free(error);
	}

	shell_dt->exe_status = eval;
	return (eval);
}
