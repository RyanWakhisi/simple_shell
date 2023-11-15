#include "main.h"

/**
 * ab_cd_current_dir - changes to the parent dir
 * @shell_dt: data environ
 *
 * Return: no return
 */
void ab_cd_current_dir(sh_dt *shell_dt)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = string_duplicate(pwd);
	shell_set_environ("OLDPWD", cp_pwd, shell_dt);
	dir = shell_dt->argum[1];
	if (string_compare(".", dir) == 0)
	{
		shell_set_environ("PWD", cp_pwd, shell_dt);
		free(cp_pwd);
		return;
	}
	if (string_compare("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	reverse_string(cp_strtok_pwd);
	cp_strtok_pwd = string_strok_c(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = string_strok_c(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			reverse_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		shell_set_environ("PWD", cp_strtok_pwd, shell_dt);
	}
	else
	{
		chdir("/");
		shell_set_environ("PWD", "/", shell_dt);
	}
	shell_dt->exe_status = 0;
	free(cp_pwd);
}

/**
 * cd_inputted_dir - changes to a directory given by user
 * @shell_dt: data relevant (directories)
 * Return: no return
 */
void cd_inputted_dir(sh_dt *shell_dt)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	dir = shell_dt->argum[1];
	if (chdir(dir) == -1)
	{
		handle_get_builtin_err(shell_dt, 2);
		return;
	}

	cp_pwd = string_duplicate(pwd);
	shell_set_environ("OLDPWD", cp_pwd, shell_dt);

	cp_dir = string_duplicate(dir);
	shell_set_environ("PWD", cp_dir, shell_dt);

	free(cp_pwd);
	free(cp_dir);

	shell_dt->exe_status = 0;

	chdir(dir);
}

/**
 * ab_cd_previous_dir - changes to the previous directory
 * @shell_dt: data environ
 * Return: no return
 */
void ab_cd_previous_dir(sh_dt *shell_dt)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = string_duplicate(pwd);

	p_oldpwd = ab_shell_extract_env("OLDPWD", shell_dt->s_env);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = string_duplicate(p_oldpwd);

	shell_set_environ("OLDPWD", cp_pwd, shell_dt);

	if (chdir(cp_oldpwd) == -1)
		shell_set_environ("PWD", cp_pwd, shell_dt);
	else
		shell_set_environ("PWD", cp_oldpwd, shell_dt);

	p_pwd = ab_shell_extract_env("PWD", shell_dt->s_env);

	write(STDOUT_FILENO, p_pwd, str_len(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	shell_dt->exe_status = 0;

	chdir(p_pwd);
}

