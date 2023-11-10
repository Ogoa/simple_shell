#include "main.h"

/**
 * _realloc - Resizes a block of memory
 * @ptr: Pointer to the memory block being resized
 * @old_size: Number of bytes currently held by the memory block 'ptr'
 * @new_size: Number of bytes to be allocated to the resized block
 *
 * Return: Pointer to the newly allocated memory block
 * Otherwise, NULL
 * Description: Address of the memory returned by this function will
 * need to be freed by the calling function
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if ((ptr == NULL || old_size == 0) && new_size)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (ptr && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (old_size == new_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (old_size < new_size)
	{
		_strncpy((char *)new_ptr, (char *)ptr, old_size);
		free(ptr);
	}
	else
	{
		_strncpy((char *)new_ptr, (char *)ptr, new_size);
		free(ptr);
	}
	return (new_ptr);
}
