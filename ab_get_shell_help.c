#include "main.h"

/**
 * shell_get_builtin_msg - A function that retrieves help builtin msgs
 * @shell_dt: argum and input_str data
 * Return: Return 0
*/
int shell_get_builtin_msg(sh_dt *shell_dt)
{

	if (shell_dt->argum[1] == 0)
		ab_shell_help_general();
	else if (string_compare(shell_dt->argum[1], "setenv") == 0)
		ab_shell_setenv_help();
	else if (string_compare(shell_dt->argum[1], "env") == 0)
		ab_shell_env_info();
	else if (string_compare(shell_dt->argum[1], "unsetenv") == 0)
		ab_shell_unsetenv_help();
	else if (string_compare(shell_dt->argum[1], "help") == 0)
		ab_help_shell();
	else if (string_compare(shell_dt->argum[1], "exit") == 0)
		exit_shell_help();
	else if (string_compare(shell_dt->argum[1], "cd") == 0)
		ab_shell_cd_help();
	else if (string_compare(shell_dt->argum[1], "alias") == 0)
		shell_alias_help_builtin();
	else
		write(STDERR_FILENO, shell_dt->argum[0],
		      str_len(shell_dt->argum[0]));

	shell_dt->exe_status = 0;
	return (1);
}
