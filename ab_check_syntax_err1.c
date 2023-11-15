#include "main.h"

/**
 * ab_check_syntax_err1 - syntax error finder
 *
 * @input_str: input_str string
 * @i: index
 * @last: last char read
 * Return: error index or 0 when there are none
 * errors
 */
int ab_check_syntax_err1(char *input_str, int i, char last)
{
	int count;

	count = 0;
	if (*input_str == '\0')
		return (0);

	if (*input_str == ' ' || *input_str == '\t')
		return (ab_check_syntax_err1(input_str + 1, i + 1, last));

	if (*input_str == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input_str == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			count = count_char_repetition(input_str, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*input_str == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			count = count_char_repetition(input_str, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (ab_check_syntax_err1(input_str + 1, i + 1, *input_str));
}
