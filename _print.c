#include "main.h"

/**
 * _print - Prints a string on the standard output stream
 * @str: The string to be printed
 *
 * Return: The number of characters printed, otherwise 0 on failure
 */
size_t _print(const char *str)
{
	size_t chars_printed = 0;

	chars_printed = _strlen(str);
	write(STDOUT_FILENO, str, chars_printed);
	return (chars_printed);
}
