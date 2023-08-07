#include "main.h"

/**
 * _strlen - Calculates the length of string
 * @str: Pointer to the string
 *
 * Return: Length of the string
 */
int _strlen(const char *str)
{
	int len;

	for (len = 0; str[len] != 0; len++)
	{
	}
	return (len);
}


/**
 * _strcpy - Copies the string pointed by src to the buffer pointed to by dest
 * @dest: Pointer to the destination buffer where the string will be copied
 * @src: Pointer to the source to be copied
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *dest, char *src)
{
	char *dest_start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';

	return (dest_start);
}


/**
 * _strcat -  Function that concatenates two strings
 * @dest: Pointer to the destination string
 * @src: Pointer to the source string to be appended
 *
 * Return: Pointer to the destination buffer
 */
char *_strcat(char *dest, const char *src)
{
	char *p;

	p = dest;
	while (*p != '\0')
	{
		p++;
	}

	while (*src != '\0')
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';

	return (dest);
}


/**
 * _strcmp - Function that compares two strings
 * @str1: First string
 * @str2: Second string
 *
 * Return: Integer that indicates the result of the comparison
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] == str2[i]; i++)
	{
		if (str1[i] == '\0')
		{
			return (0);
		}
	}
	return (str1[i] - str2[i]);
}


/**
 * rev_string - A function that reverses a string
 * @str: String to be reversed
 */
void rev_string(char *str)
{
	int i, j, len;
	char temp;

	len = _strlen(str);

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
