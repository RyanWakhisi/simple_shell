#include "main.h"

/**
 * go_to_next_cli - go to the nxt CLI
 * @list_s: sep list
 * @list_l: command line list
 * @shell_dt: shell's data
 * Return: no return
 */
void go_to_next_cli(separate_lst **list_s, ln_lst **list_l, sh_dt *shell_dt)
{
	int loop_sep;
	separate_lst *ls_s;
	ln_lst *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (shell_dt->exe_status == 0)
		{
			if (ls_s->separator_c == '&' || ls_s->separator_c == ';')
				loop_sep = 0;
			if (ls_s->separator_c == '|')
				ls_l = ls_l->nxt, ls_s = ls_s->nxt;
		}
		else
		{
			if (ls_s->separator_c == '|' || ls_s->separator_c == ';')
				loop_sep = 0;
			if (ls_s->separator_c == '&')
				ls_l = ls_l->nxt, ls_s = ls_s->nxt;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->nxt;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

