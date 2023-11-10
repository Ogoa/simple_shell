#include "main.h"

/**
 * _strcmp - Compares two strings to evaluate if they are similar
 * @str1: The first string
 * @str2: The second string
 *
 * Return: 1 if the two strings are similar, otherwise 0
 */
int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	if (str1 == NULL || str2 == NULL)
		return (0);
	if (_strlen(str1) != _strlen(str2))
		return (0);
	while (*(str2 + i) != '\0')
	{
		if (*(str1 + i) != *(str2 + i))
			return (0);
		i++;
	}
	return (1);
}
