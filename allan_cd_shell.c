#include "main.h"

/**
 * cd_shell - changes current directory
 *
 * @datash: data relevant
 * Return: 1 on success
 */
int cd_shell(data_shell *datash)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = datash->args[1];

	if (dir != NULL)
	{
		ishome = shell_strcmp("$HOME", dir);
		ishome2 = shell_strcmp("~", dir);
		isddash = shell_strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		ab_cd_to_home(datash);
		return (1);
	}

	if (shell_strcmp("-", dir) == 0)
	{
		ab_cd_previous(datash);
		return (1);
	}

	if (shell_strcmp(".", dir) == 0 || shell_strcmp("..", dir) == 0)
	{
		ab_cd_dot(datash);
		return (1);
	}

	ab_cd_to(datash);

	return (1);
}
