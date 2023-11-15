#include "main.h"

/**

 * is_executable_cmd - checks if file is executable
 * @shell_dt: data_structure
 * Return: 0 if non-executable, other number if it does
 */
int is_executable_cmd(sh_dt *shell_dt)
{
	struct stat st;
	int i;
	char *input_str;

	input_str = shell_dt->argum[0];
	for (i = 0; input_str[i]; i++)
	{
		if (input_str[i] == '.')
		{
			if (input_str[i + 1] == '.')
				return (0);
			if (input_str[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input_str[i] == '/' && i != 0)
		{
			if (input_str[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(input_str + i, &st) == 0)
	{
		return (i);
	}
	handle_get_builtin_err(shell_dt, 127);
	return (-1);
}

/**
 * ab_shell_w - locates a command
 * @cmd: command name
 * @s_env: environment variable
 * Return: location of the command.
 */
char *ab_shell_w(char *cmd, char **s_env)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	path = ab_shell_extract_env("PATH", s_env);
	if (path)
	{
		ptr_path = string_duplicate(path);
		len_cmd = str_len(cmd);
		token_path = string_strok_c(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (check_if_current_dir(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = str_len(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			string_copy(dir, token_path);
			string_concat(dir, "/");
			string_concat(dir, cmd);
			string_concat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = string_strok_c(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}