#include "main.h"
/**
 * attach_var_after_node - append variable at the end of var list
 * @lead: head of the linked list.
 * @lvar: length of str.
 * @val: variable value
 * @lval: str length
 * Return: address of the head.
 */
variable_r *attach_var_after_node(variable_r **lead, int lvar, char *val, int lval)
{
	variable_r *new, *temp;

	new = malloc(sizeof(variable_r));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->nxt = NULL;
	temp = *lead;
	if (temp == NULL)
	{
		*lead = new;
	}
	else
	{
		while (temp->nxt != NULL)
			temp = temp->nxt;
		temp->nxt = new;
	}

	return (*lead);
}
/**
 * clear_var_list - empty variable list
 * @lead: head of linked list
 * Return: Nothing
 */
void clear_var_list(variable_r **lead)
{
	variable_r *temp;
	variable_r *current;

	if (lead != NULL)
	{
		current = *lead;
		while ((temp = current) != NULL)
		{
			current = current->nxt;
			free(temp);
		}
		*lead = NULL;
	}
}
