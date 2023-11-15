#include "main.h"

/**
 * get_interger_length - A function that get the lenght of a number.
 * @n: integer number.
 * Return: Number length.
 */
int get_interger_length(int n)
{
	unsigned int num1;
	int lenght = 1;

	if (n < 0)
	{
		lenght++;
		num1 = n * -1;
	}
	else
	{
		num1 = n;
	}
	while (num1 > 9)
	{
		lenght++;
		num1 = num1 / 10;
	}

	return (lenght);
}
/**
 * convert_int_to_string - A function to convert an int into string.
 * @n: type int number
 * Return: Str.
 */
char *convert_int_to_string(int n)
{
	unsigned int num1;
	int lenght = get_interger_length(n);
	char *buff;

	buff = malloc(sizeof(char) * (lenght + 1));
	if (buff == 0)
		return (NULL);

	*(buff + lenght) = '\0';

	if (n < 0)
	{
		num1 = n * -1;
		buff[0] = '-';
	}
	else
	{
		num1 = n;
	}

	lenght--;
	do {
		*(buff + lenght) = (num1 % 10) + '0';
		num1 = num1 / 10;
		lenght--;
	}
	while (num1 > 0)
		;
	return (buff);
}

