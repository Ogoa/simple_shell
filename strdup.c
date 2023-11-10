#include "main.h"

/**
 * _strdup - Duplicates an string
 * @str: The string to be duplicted in memory
 *
 * Return: Pointer to the memory in heap holding a duplicate of 'str'
 * Otheriwse, NULL on failure
 * Description: Address of the memory returned by this function will
 * need to be freed by the calling function
 */
char *_strdup(const char *str)
{
	char *dup_str; /* Pointer to the string duplicate */
	int i = 0;

	if (str == NULL)
		return (NULL);
	dup_str = malloc(sizeof(char) * (_strlen(str) + 1));
	if (dup_str == NULL) /* Handling malloc failure */
		return (NULL);
	while (*(str + i) != '\0')
	{
		*(dup_str + i) = *(str + i);
		i++;
	}
	*(dup_str + i) = '\0';
	return (dup_str);
}
