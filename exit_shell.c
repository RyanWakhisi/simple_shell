#include "simple_shell.h"

void exit_shell(char *command, char **env)
{
	(void) command;

        while (*env != NULL) {
               write(1, *env, strlen(*env));
               write(1, "\n", 1);
               env++;
        }
}
