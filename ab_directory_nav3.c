#include "main.h"

/**
 * ab_cd_to_dire_home - a function that changes to home dir
 *
 * @shell_dt: data environ
 * Return: no return
 */
void ab_cd_to_dire_home(sh_dt *shell_dt)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = string_duplicate(pwd);

	home = ab_shell_extract_env("HOME", shell_dt->s_env);

	if (home == NULL)
	{
		shell_set_environ("OLDPWD", p_pwd, shell_dt);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		handle_get_builtin_err(shell_dt, 2);
		free(p_pwd);
		return;
	}

	shell_set_environ("OLDPWD", p_pwd, shell_dt);
	shell_set_environ("PWD", home, shell_dt);
	free(p_pwd);
	shell_dt->exe_status = 0;
}
