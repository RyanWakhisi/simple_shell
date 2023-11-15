#include "main.h"

/**
 * ab_clear_data - A function that frees data struct
 * @shell_dt: data struct
 * Return: no return
 */
void ab_clear_data(sh_dt *shell_dt)
{
	unsigned int i;

	for (i = 0; shell_dt->s_env[i]; i++)
	{
		free(shell_dt->s_env[i]);
	}

	free(shell_dt->s_env);
	free(shell_dt->proc_id);
}