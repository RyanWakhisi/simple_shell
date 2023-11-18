#include "simple_shell.h"

/**
 *print_environment - Function to print the environment
 *@environment: the environment
 */
void print_environment(char *command, char **env)
{
	(void) command;
	
	while (*env != NULL) {
	       write(1, *env, strlen(*env));
	       write(1, "\n", 1);
	       env++;
    	}
}
