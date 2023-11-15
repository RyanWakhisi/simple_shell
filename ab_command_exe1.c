#include "main.h"

/**
 * check_if_current_dir - checks if ":" is in the current dir.
 * @path: type char pointer.
 * @i: type int pointer of index.
 * Return: 1 if path = searchable in the cd, 0 otherwise.
 */
int check_if_current_dir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}




/**
 * inspect_cmd_error_exists - verifies if user has permissions to access
 * @dir: destination directory
 * @shell_dt: data structure
 * Return: 1 if there is an error, 0 if not
 */
int inspect_cmd_error_exists(char *dir, sh_dt *shell_dt)
{
	if (dir == NULL)
	{
		handle_get_builtin_err(shell_dt, 127);
		return (1);
	}

	if (string_compare(shell_dt->argum[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			handle_get_builtin_err(shell_dt, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(shell_dt->argum[0], X_OK) == -1)
		{
			handle_get_builtin_err(shell_dt, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * execute_cmd_input - executes cmd lines
 * @shell_dt: argum and input_str data
 * Return: 1 on success.
 */
int execute_cmd_input(sh_dt *shell_dt)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_executable_cmd(shell_dt);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = ab_shell_w(shell_dt->argum[0], shell_dt->s_env);
		if (inspect_cmd_error_exists(dir, shell_dt) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = ab_shell_w(shell_dt->argum[0], shell_dt->s_env);
		else
			dir = shell_dt->argum[0];
		execve(dir + exec, shell_dt->argum, shell_dt->s_env);
	}
	else if (pd < 0)
	{
		perror(shell_dt->avg[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	shell_dt->exe_status = state / 256;
	return (1);
}
