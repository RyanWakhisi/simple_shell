#include "main.h"

/**
 * set_data - A function to Initialize data struct
 * @shell_dt: data struct
 * @avg: arg vector
 * Return: Nothing
 */
void ab_set_data(sh_dt *shell_dt, char **avg)
{
	unsigned int i;
	
	shell_dt->avg = avg;
	shell_dt->input_str = NULL;
	shell_dt->argum = NULL;
	shell_dt->exe_status = 0;
	shell_dt->cmd_count = 1;
	
	for (i = 0; environ[i]; i++);
	shell_dt->s_env = malloc(sizeof(char *) * (i + 1));
	for (i = 0; environ[i]; i++)
	{
		shell_dt->s_env[i] = string_duplicate(environ[i]);
	}
	shell_dt->s_env[i] = NULL;
	shell_dt->proc_id = convert_int_to_string(getpid());
}
