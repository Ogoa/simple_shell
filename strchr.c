#include "main.h"

/**
 * _strchr - Evaluates if a character occurs at least once in a given string
 * @str: String to be parsed through during the search
 * @c: The particular character whose occurrence in 'str' is being searched
 * for
 *
 * Return: Pointer to the position of the character in the string
 * if a match is found
 * Otherwise, NULL if no match is founc
 */
char *_strchr(const char *str, int c)
{
	int i = 0;

	if (str == NULL || c == 0)
		return (NULL);
	while (*(str + i) != '\0')
	{
		if (c == *(str + i))
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
