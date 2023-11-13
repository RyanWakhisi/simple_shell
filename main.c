#include "main.h"

/**
 * main - This is the main program entry point
 * @ac: The argument count
 * @avg: The argument vector
 * Return: 0 if success
 */

int main(int ac, char **avg)
{
	sh_dt shell_dt;
	(void) ac;

	signal(SIGINT, get_interrupt_sig);
	ab_set_data(&shell_dt, avg);
	ab_loop_through(&shell_dt);
	ab_clear_data(&shell_dt);
	if (shell_dt.exe_status < 0)
		return (255);
	return (shell_dt.exe_status);
}
