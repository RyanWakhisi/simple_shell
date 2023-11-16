#include "main.h"

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	shell_set_struct_data(&datash, av);
	shell_loop_through_data(&datash);
	shell_free_data_held(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
