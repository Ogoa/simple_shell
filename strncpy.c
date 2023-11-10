#include "main.h"

/**
 * _strncpy - Copies contents from one memory block to another memory block
 * @dest: Pointer to the memory address being copied to
 * @src: Pointer to the memory address being copied from
 * @nmemb: The number of characters being copied from 'src' to 'dest'
 *
 * Return: Pointer to the destination string, otherwise NULL
 */
char *_strncpy(char *dest, const char *src, size_t nmemb)
{
	size_t i = 0;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);
	while ((*(src + i) != '\0') && i < nmemb)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	for (; i < nmemb; i++)
		*(dest + i) = '\0';
	return (dest);
}
