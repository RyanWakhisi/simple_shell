#include "main.h"

/**
 * shell_envir_checker - checks if the typed variable is an env variable
 *
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: no return
 */
void shell_envir_checker(r_var **h, char *in, data_shell *data)
{
	int row, chr, j, lval;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = shell_strlen(_envr[row] + chr + 1);
				shell_add_rvar_node(h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	shell_add_rvar_node(h, j, NULL, 0);
}

/**
 * shell_var_checker - check if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */
int shell_var_checker(r_var **h, char *in, char *st, data_shell *data)
{
	int i, lst, lpd;

	lst = shell_strlen(st);
	lpd = shell_strlen(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				shell_add_rvar_node(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				shell_add_rvar_node(h, 2, data->pid, lpd), i++;
			else if (in[i + 1] == '\n')
				shell_add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				shell_add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				shell_add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				shell_add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				shell_add_rvar_node(h, 0, NULL, 0);
			else
				shell_envir_checker(h, in + i, data);
		}
	}

	return (i);
}

/**
 * shell_new_input - replaces string into variables
 *
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *shell_new_input(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *indx;
	int i, j, k;

	indx = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (k = 0; k < indx->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx->len_val; k++)
				{
					new_input[i] = indx->val[k];
					i++;
				}
				j += (indx->len_var);
				i--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * shell_var_rep - calls functions to replace string into vars
 *
 * @input: input string
 * @datash: data structure
 * Return: replaced string
 */
char *shell_var_rep(char *input, data_shell *datash)
{
	r_var *head, *indx;
	char *status, *new_input;
	int olen, nlen;

	status = shell_itoa(datash->status);
	head = NULL;

	olen = shell_var_checker(&head, input, status, datash);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = shell_new_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	shell_free_list_rvar(&head);

	return (new_input);
}
