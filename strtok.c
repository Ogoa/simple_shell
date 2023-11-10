#include "main.h"

/**
 * _strtok - Extracts tokens from a string
 * @str: The string to be tokenised
 * @delim: The string containing the individual bytes that are delimiters
 * in 'str'
 *
 * Return: Pointer to the memory location holding the string token
 * Otherwise, NULL if no token is found
 * Description: On the first call 'str' should be specified while on all
 * subsequent calls, 'str' must be NULL
 * All addresses returned by this function should be freed by the calling
 * function
 */
char *_strtok(char *str, const char *delim)
{
	static char *string;
	char *token;
	int i = 0;
	int n = 0;

	if (str)
		string = str;
	if (*(string + i) != '\0')
	{
		/* Parsing the string until a delimiter is encountered */
		while ((*(string + i) != '\0') && (_strchr(delim, *(string + i)) == NULL))
			i++;
		if (i == 0) /* Handling consecutive delimiters */
		{
			string++;
			return (_strtok(NULL, delim));
		}
		token = malloc(sizeof(char) * (i + 1));
		if (token == NULL)
			return (NULL);
		for (n = 0; n < i; n++)
		{
			*(token + n) = *string;
			string++;
		}
		*(token + n) = '\0';
		if (*string != '\0')
			string++;
		return (token);
	}
	return (NULL);
}
