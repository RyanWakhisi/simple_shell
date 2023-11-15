#include "main.h"

/**
 * assign_var_get_ln - assigns the line var for ab_shell_get_line
 * @lineptr: Buff to store the input_str
 * @buff: str called to line
 * @n: line size
 * @j: buff size
 */
void assign_var_get_ln(char **lineptr, size_t *n, char *buff, size_t j)
{

	if (*line + ptr == NULL)
	{
		if  (j > BUFSIZE)
			*n = j;

		else
			*n = BUFSIZE;
		*lineptr = buff;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buff;
	}
	else
	{
		string_copy(*lineptr, buff);
		free(buff);
	}
}
/**
 * ab_shell_get_line - A function to read input from strm
 * @lineptr: buff that stores the input_str
 * @n: size of lineptr
 * @strm: strm to read from
 * Return: No of bytes
 */
ssize_t ab_shell_get_line(char **lineptr, size_t *n, FILE *strm)
{
	int i;
	static ssize_t input_str;
	ssize_t retval;
	char *buff;
	char t = 'z';

	if (input_str == 0)
		fflush(strm);
	else
		return (-1);
	input_str = 0;

	buff = malloc(sizeof(char) * BUFSIZE);
	if (buff == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input_str == 0))
		{
			free(buff);
			return (-1);
		}
		if (i == 0 && input_str != 0)
		{
			input_str++;
			break;
		}
		if (input_str >= BUFSIZE)
			buff = realloc_memory(buff, input_str, input_str + 1);
		buff[input_str] = t;
		input_str++;
	}
	buff[input_str] = '\0';
	assign_var_get_ln(lineptr, n, buff, input_str);
	retval = input_str;
	if (i != 0)
		input_str = 0;
	return (retval);
}
