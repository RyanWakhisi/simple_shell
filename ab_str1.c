#include "main.h"

/**
 * string_concat - A function that concatenates two strings
 * @dest: ptr to the dest of the copied str
 * @src: ptr to the source of str
 * Return: dest
 */
char *string_concat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
/**
 * *string_copy - it is a function that Copies the string pointed to by src.
 * @dest: ptr to the dest of the copied str
 * @src: ptr to the source of str
 * Return: dest.
 */
char *string_copy(char *dest, char *src)
{

	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}
/**
 * string_compare - A function that compares two strings.
 * @s1: string1
 * @s2: string2
 * Return: Always 0.
 */
int string_compare(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
/**
 * string_locate_chr_pos - A function to locate a character in a str
 * @s: string.
 * @c: character.
 * Return: ptr to the first appearance of the character c.
 */
char *string_locate_chr_pos(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}

