#include "main.h"

/**
 * shell_get_help - function that retrieves help messages according builtin
 * @datash: data structure (args and input)
 * Return: Return 0
*/
int shell_get_help(data_shell *datash)
{

	if (datash->args[1] == 0)
		help_builtin_general();
	else if (shell_strcmp(datash->args[1], "setenv") == 0)
		shell_help_env_set();
	else if (shell_strcmp(datash->args[1], "env") == 0)
		shell_builtin_env_help();
	else if (shell_strcmp(datash->args[1], "unsetenv") == 0)
		unsetenv_shell_help();
	else if (shell_strcmp(datash->args[1], "help") == 0)
		shell_aux_help();
	else if (shell_strcmp(datash->args[1], "exit") == 0)
		shell_help_exit();
	else if (shell_strcmp(datash->args[1], "cd") == 0)
		shell_help_cd();
	else if (shell_strcmp(datash->args[1], "alias") == 0)
		shell_help_alias();
	else
		write(STDERR_FILENO, datash->args[0],
		      shell_strlen(datash->args[0]));

	datash->status = 0;
	return (1);
}
