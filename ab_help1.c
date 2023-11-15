#include "main.h"
/**
 * ab_shell_env_info - Assistance info for shell inbuilts
 * Return: Nothing
 */
void ab_shell_env_info(void)
{
	char *help = "env: env [option] [name=value] [command [argum]]\n\t";

	write(STDOUT_FILENO, help, str_len(help));
	help = "Print shell's environment.\n";
	write(STDOUT_FILENO, help, str_len(help));
}
/**
 * ab_shell_setenv_help - Assistance for shell set environment
 * Return: no return
 */
void ab_shell_setenv_help(void)
{

	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, str_len(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, str_len(help));
	help = "Define environment again\n";
	write(STDOUT_FILENO, help, str_len(help));
}
/**
 * ab_shell_unsetenv_help - Assistance for shell unset environment
 * Return: no return
 */
void ab_shell_unsetenv_help(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, str_len(help));
	help = "Eliminate entry form env\n";
	write(STDOUT_FILENO, help, str_len(help));
}


/**
 * shell_help_general - Entry point for all assistance
 * Return: Nothing
 */
void shell_help_general(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, str_len(help));
	help = "Defiened Internally.Type 'help' for list view";
	write(STDOUT_FILENO, help, str_len(help));
	help = "Type 'help name' to learn more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help, str_len(help));
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, str_len(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, str_len(help));
	help = "[argum]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, str_len(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, str_len(help));
}
/**
 * shell_help_exit - Assistance for built in exit
 * Return: Nothing
 */
void shell_help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, str_len(help));
	help = "Exits with an exe_status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, help, str_len(help));
	help = "status of the last command executed\n";
	write(STDOUT_FILENO, help, str_len(help));
}
