#include "main.h"

/**
 * string_duplicate - A function that duplicates a str in the heap memory.
 * @s: char pointer str
 * Return: duplicated str
 */
char *string_duplicate(const char *s)
{
	char *new;
	size_t len;

	len = str_len(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	copy_into_new_mem(new, s, len + 1);
	return (new);
}

/**
 * str_len - A function to Return the str length
 * @s: char pointer
 * Return: Always 0.
 */
int str_len(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * str_compare_chars - A function that compares chars of strings
 * @str: input_str string.
 * @dlm: delimiter.
 * Return: 1 if equals, 0 if not.
 */
int str_compare_chars(char str[], const char *dlm)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; dlm[j]; j++)
		{
			if (str[i] == dlm[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * string_strok_c - splits a string by some delimiter.
 * @str: input_str .
 * @dlm: delimiter.
 * Return: The splitted string
 */
char *string_strok_c(char str[], const char *dlm)
{
	static char *str_splitted, *string_end;
	char *string_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (str_compare_chars(str, dlm))
			return (NULL);
		str_splitted = str;
		i = str_len(str);
		string_end = &str[i];
	}
	string_start = str_splitted;
	if (string_start == string_end)
		return (NULL);

	for (bool = 0; *str_splitted; str_splitted++)
	{
		if (str_splitted != string_start)
			if (*str_splitted && *(str_splitted - 1) == '\0')
				break;
		for (i = 0; dlm[i]; i++)
		{
			if (*str_splitted == dlm[i])
			{
				*str_splitted = '\0';
				if (str_splitted == string_start)
					string_start++;
				break;
			}
		}
		if (bool == 0 && *str_splitted)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (string_start);
}

/**
 * check_if_digit - A function to define if string passed is a number
 * @s: input_str string
 * Return: 1 if string is number, otherwise 0
 */
int check_if_digit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
