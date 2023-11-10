#include "main.h"

/**
 * free_arr - Frees an array of dynamically allocated pointers
 * @arr: Pointer to the array of pointers
 *
 * Return: Nothing
 */
void free_arr(char **arr)
{
	int i = 0;

	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
	}
}
