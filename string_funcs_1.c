#include "main.h"

/**
 * _strspn - Get the length of a prefix substring
 * @str: The string to check
 * @accept: A string containing characters to check against
 *
 * Return: The number of bytes in the initial segment of str
 */
unsigned int _strspn(char *str, char *accept)
{
	unsigned int len;
	char *ptr;

	len = 0;

	while (*str != '\0')
	{
		for (ptr = accept; *ptr != '\0'; ptr++)
		{
			if (*str == *ptr)
			{
				len++;
				break;
			}
		}
		if (*ptr == '\0')
		{
			break;
		}
		str++;
	}
	return (len);
}



/**
 * _strchr - Locates the first occurrence of a character in a string
 * @str: Pointer to the string to be searched
 * @chr: The character to be located
 *
 * Return: A pointer to the first occurrence of the character chr, in
 * ** the string str, or NULL if ctr is not found
 */
char *_strchr(char *str, char chr)
{
	while (*str != '\0')
	{
		if (*str == chr)
		{
			return (str);
		}
		str++;
	}
	if (*str == chr)
	{
		return (str);
	}

	return (NULL);
}



/**
 * cmp_chars - Compare characters of two strings
 * @str: Input string to be compared
 * @delim: Delimiter string to compare against
 *
 * Return: 1 if all characters in str are found in delim, 0 otherwise
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (str[i] == delim[j])
			{
				break;
			}
		}

		if (delim[j] == '\0')
		{
			return (0);
		}
	}

	return (1);
}


/**
 * _strdup - Duplicates a string in the heap memory
 * @str: Pointer to the source string to be duplicated
 *
 * Return: Pointer to the newly allocated duplcated string.
 * ** NULL if memory allocation fails or str is NULL
 */
char *_strdup(const char *str)
{
	char *new_str;
	size_t len;

	len = _strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));

	if (new_str == NULL)
		return (NULL);
	_memcpy(new_str, str, len + 1);

	return (new_str);
}
