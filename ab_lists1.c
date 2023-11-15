#include "main.h"

/**
 * append_a_tail_node - adds separator at tail.
 * @lead: head of the linked list.
 * @sep: separator observed/
 * Return: head's address.
 */
separate_lst *append_a_tail_node(separate_lst **lead, char sep)
{
	separate_lst *new, *temp;

	new = malloc(sizeof(separate_lst));
	if (new == NULL)
		return (NULL);

	new->separator_c = sep;
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
 * free_separate_list - empty a separate list
 * @lead: linked list head.
 * Return: Nothing
 */
void free_separate_list(separate_lst **lead)
{
	separate_lst *temp;
	separate_lst *current;

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

/**
 * append_tail_node - append node tail
 * @lead: linked list's head.
 * @line: instruction line.
 * Return: address of the head.
 */
ln_lst *append_tail_node(ln_lst **lead, char *line)
{
	ln_lst *new, *temp;

	new = malloc(sizeof(ln_lst));
	if (new == NULL)
		return (NULL);

	new->line = line;
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
 * free_linked_list - frees a linked list
 * @lead: head of the linked list.
 * Return: nothing.
 */
void free_linked_list(ln_lst **lead)
{
	ln_lst *temp;
	ln_lst *current;

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
