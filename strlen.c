#include "main.h"

/**
 * _strlen - Evaluate the length of a string
 * @str: The string being evaluated
 *
 * Return: The number of characters in the string, otherwise 0
 */
size_t _strlen(const char *str)
{
	size_t str_length = 0;

	if (str == NULL)
		return (0);
	while (*(str + str_length) != '\0')
		str_length++;
	return (str_length);
}
