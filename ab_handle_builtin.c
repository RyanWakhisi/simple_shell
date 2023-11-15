#include "main.h"

/**
 * shell_print_cmd_arg - A function builtin that prints the command in the argum
 * @cmd: command
 * Return: builtin command function pointer
 */
int (*shell_print_cmd_arg(char *cmd))(sh_dt *)
{
	inbuilt_t builtin[] = {
		{ "env", shell_env },
		{ "exit", shell_c_exit },
		{ "setenv", shell_setenv },
		{ "unsetenv", shell_unsetenv },
		{ "cd", cd_shell_c },
		{ "help", get_shell_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (string_compare(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}
