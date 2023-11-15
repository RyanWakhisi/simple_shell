#include "main.h"

/**
 * execute_builtins - A function to find built-ins and commands
 * @shell_dt: data relevant (argum)
 * Return: 1 on success.
 */
int execute_builtins(sh_dt *shell_dt)
{
	int (*builtin)(sh_dt *shell_dt);

	if (shell_dt->argum[0] == NULL)
		return (1);

	builtin = shell_print_cmd_arg(shell_dt->argum[0]);

	if (builtin != NULL)
		return (builtin(shell_dt));

	return (execute_cmd_input(shell_dt));
}

