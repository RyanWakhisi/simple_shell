#include "main.h"

/**
 * handle_interrupt_signal - Handle the "crtl + c" function call in the prompt
 * @sig_handler: Signal_handler
 */
void handle_interrupt_signal(int sig_handler)
{
	(void)sig_handler;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
