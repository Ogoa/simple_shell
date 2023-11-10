#include "main.h"
#define BUFFER_SIZE 200

/**
 * _getline - Reads an entire line of text from a stream
 * @lineptr: Pointer to the buffer containing the text read
 * @n: Size of the buffer at the time of this function call
 * @stream: The stream where the line is being read from
 *
 * Return: The number of characters read, otherwise -1 on failure to read
 * a line or on end-of-file
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t i = 0;
	char c;

	if (lineptr == NULL || *lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while ((c = (char)fgetc(stream)) != EOF)
	{
		if (i >= *n - 1) /* Check if buffer is full to prevent an overflow */
		{
			*lineptr = _realloc(*lineptr, *n, *n * 2);
			*n = *n * 2;
			if (*lineptr == NULL)
				return (-1);
		}
		*(*lineptr + i) = c;
		if (c == '\n') /* Terminate if the end of a line is reached */
		{
			*(*lineptr + ++i) = '\0';
			return (i);
		}
		i++;
	}
	return (-1);
}
