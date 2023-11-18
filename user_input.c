#include "simple_shell.h"

/**
 * read_user_command - Reads user command
 * @command: command
 * @size: size
 */
void read_user_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print_output("\n");
			exit(0);
		}
		else
		{
			print_output("Error while reading input. \n");
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
