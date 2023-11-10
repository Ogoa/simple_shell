#include "main.h"

/**
 * _strcpy - Copies contents from one memory block to another memory block
 * @dest: Pointer to the memory address being copied to
 * @src: Pointer to the memory address being copied from
 *
 * Return: Pointer to the destination string, otherwise NULL
 * Description: This function does not take care of overflow
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i = 0;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
