#include "main.h"
/**
 * swap_char - swaps(|) and (&) for charaters that are not printed
 * @input_str: string input
 * @bool: boolean swap
 * Return: The string that has been swapped.
 */
char *swap_char(char *input_str, int bool)
{
	int i;

	if (bool == 0)
	{
		for (i = 0; input_str[i]; i++)
		{
			if (input_str[i] == '|')
			{
				if (input_str[i + 1] != '|')
					input_str[i] = 16;
				else
					i++;
			}

			if (input_str[i] == '&')
			{
				if (input_str[i + 1] != '&')
					input_str[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; input_str[i]; i++)
		{
			input_str[i] = (input_str[i] == 16 ? '|' : input_str[i]);
			input_str[i] = (input_str[i] == 12 ? '&' : input_str[i]);
		}
	}
	return (input_str);
}

/**
 * attach_sep_nodes - add separators in the lists
 * @head_s: head of sep list
 * @head_l: head of command lines list
 * @input_str: string input
 * Return: nothing
 */
void attach_sep_nodes(separate_lst **head_s, ln_lst **head_l, char *input_str)
{
	int i;
	char *line;

	input_str = swap_char(input_str, 0);

	for (i = 0; input_str[i]; i++)
	{
		if (input_str[i] == ';')
			append_a_tail_node(head_s, input_str[i]);

		if (input_str[i] == '|' || input_str[i] == '&')
		{
			append_a_tail_node(head_s, input_str[i]);
			i++;
		}
	}

	line = string_strok_c(input_str, ";|&");
	do {
		line = swap_char(line, 1);
		append_tail_node(head_l, line);
		line = string_strok_c(NULL, ";|&");
	} while (line != NULL);
}


