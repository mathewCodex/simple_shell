#include "main.h"

/**
 * _isdigit - Program that checks for a digit (0 through 9)
 * @chr: Charater to be checked
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(char chr)
{
	if (chr >= '0' && chr <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


/**
 * _strtok - Splits a string by some delimiter
 * @str: Input string to be split
 * @delim: Delimiter string
 *
 * Return: Pointer to the next token or NULL if no more tokens
 */
char *_strtok(char str[], const char *delim)
{
	static char *last_token;
	char *start_token;
	unsigned int i;

	last_token = NULL;
	if (str != NULL)
		last_token = str;
	if (last_token == NULL)
		return (NULL);
	start_token = last_token;

	while (*last_token)
	{
		for (i = 0; delim[i]; i++)
		{
			if (*last_token == delim[i])
			{
				*last_token = '\0';
				last_token++;
				return (start_token);
			}
		}
		if (*last_token == '\0')
			break;
		last_token++;
	}
	last_token = NULL;
	return (start_token);
}

