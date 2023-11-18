#include "simple_shell.h"

/**
  * concat_two_strings - Concatenates two strings
  * @dest: pointer to destination string
  * @src: pointer to source string
  *
  * Return: A pointer to the final string
  */
char *concat_two_strings(char *dest, char *src)
{
	int len = 0, i;

	while (dest[len])
	{
		len++;
	}

	for (i = 0; src[i] != 0; i++)
	{
		dest[len] = src[i];
		len++;
	}

	dest[len] = '\0';
	return (dest);
}
