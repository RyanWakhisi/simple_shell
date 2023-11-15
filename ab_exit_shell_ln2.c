#include "main.h"

/**

 * exec_exit_shell - A function to exit the shell
 * @shell_dt: exe_status and argum data
 * Return: 0 on success.
 */
int exec_exit_shell(sh_dt *shell_dt)
{
	unsigned int u_status;
	int is_digit;
	int str_len;
	int big_number;

	if (shell_dt->argum[1] != NULL)
	{
		u_status = convert_string_to_int(shell_dt->argum[1]);
		is_digit = check_if_digit(shell_dt->argum[1]);
		str_len = str_len(shell_dt->argum[1]);
		big_number = u_status > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			handle_get_builtin_err(shell_dt, 2);
			shell_dt->exe_status = 2;
			return (1);
		}
		shell_dt->exe_status = (u_status % 256);
	}
	return (0);
}