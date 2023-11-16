#include "simple_shell.h"

/**
 * print_output - prints output
 * @message : message to be printed
 */

void print_output(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}
