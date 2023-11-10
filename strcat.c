#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: The string being appended to
 * @src: The string being appended to 'dest'
 *
 * Return: Address of the resulting string, otherwise NULL on failure
 * Description: The address of the memory returned by this function should
 * be freed by the calling function
 */
char *_strcat(char *dest, const char *src)
{
	size_t i = 0;
	size_t j = 0;
	size_t dest_len = 0;
	size_t src_len = 0;
	char *new_string;

	if (dest == NULL || src == NULL)
		return (NULL);
	dest_len = _strlen(dest);
	src_len = _strlen(src);
	new_string = malloc(dest_len + src_len + 1);
	if (new_string == NULL)
		return (NULL);
	for (i = 0; i < dest_len; i++)
		*(new_string + i) = *(dest + i);
	for (j = 0; j < src_len; j++)
		*(new_string + i + j) = *(src + j);
	*(new_string + i + j) = '\0';
	return (new_string);
}
