#include "main.h"
/**
 * ab_help_shell - Assistance for the builtin help.
 * Return: Nothing
 */
void ab_help_shell(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, str_len(help));
	help = "\tDisplay information for inbuilt instructions.\n ";
	write(STDOUT_FILENO, help, str_len(help));
	help = "Print summaries of inbuilt commands.\n";
	write(STDOUT_FILENO, help, str_len(help));
}
/**
 * shell_alias_help_builtin - Assistance for the builtin alias.
 * Return: no return
 */
void shell_alias_help_builtin(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, str_len(help));
	help = "\tDefine or print aliases.\n ";
	write(STDOUT_FILENO, help, str_len(help));
}
/**
 * ab_shell_cd_help - Assistance for inbuiltin cd.
 * Return: no return
 */
void ab_shell_cd_help(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, str_len(help));
	help = "\tChange shell's current directory.\n ";
	write(STDOUT_FILENO, help, str_len(help));
}
