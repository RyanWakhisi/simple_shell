#include "main.h"

/**
 * cd_change_curr_dir - changes current directory
 * @shell_dt: data relevant environ
 * Return: 1 on success
 */
int cd_change_curr_dir(sh_dt *shell_dt)
{
	char *dir;
	int home_1, home_2, is_dash;

	dir = shell_dt->argum[1];

	if (dir != NULL)
	{
		home_1 = string_compare("$HOME", dir);
		home_2 = string_compare("~", dir);
		is_dash = string_compare("--", dir);
	}

	if (dir == NULL || !home_1 || !home_2 || !is_dash)
	{
		ab_cd_to_dire_home(shell_dt);
		return (1);
	}

	if (string_compare("-", dir) == 0)
	{
		ab_cd_previous_dir(shell_dt);
		return (1);
	}

	if (string_compare(".", dir) == 0 || string_compare("..", dir) == 0)
	{
		ab_cd_current_dir(shell_dt);
		return (1);
	}

	cd_inputted_dir(shell_dt);

	return (1);
}
