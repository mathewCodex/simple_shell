#include "main.h"

/**
 * read_line - Read a line from the standard input
 *
 * @eof_indicator: Pointer to an integer variable to store the
 * **return value of getline function
 *
 * Return: Pointer to the input string
 */
char *read_line(int *eof_indicator)
{
	char *input;
	size_t buffer_size;

	input = NULL;
	buffer_size = 0;
	*eof_indicator = getline(&input, &buffer_size, stdin);

	return (input);
}
