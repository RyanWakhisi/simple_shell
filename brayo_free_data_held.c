#include "main.h"
/**
 * shell_free_data_held - frees data structure
 *
 * @datash: data structure
 * Return: no return
 */

void shell_free_data_held(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}
