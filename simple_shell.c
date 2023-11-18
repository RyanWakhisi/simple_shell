#include"simple_shell.h"
/**
*main-Mainentryoftheprogram
*Return:returns0;
*/
int main(int argc, char **argv, char **env)
{
	char command[120];
	(void)argc;
	(void) argv;
	/* char **environment = get_environment();*/

	while (1)
	{
		if (isatty(0) == 1)
		{
			write(1, "$ ", 2);
		}
		read_user_command(command, sizeof(command));
		if (strcmp(command, "exit") == 0)
		{
			exit_shell(command,env);
		}
		else if (strcmp(command, "env") == 0)
		{
			print_environment(command,env);
		}
		else
		{
			execute_command(command,env);
		}
	}

	return (0);
}
