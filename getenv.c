#include "main.h"

/**
 * _getenv - Searches the environment list to find the environment variable
 * name, and returns a pointer to the corresponding value string
 * @path: String representing the 8environment variable name being searched
 * for
 *
 * Return: Pointer to the value string of the environment variable
 * Otherwise, NULL if no match is found
 * Description: The address of the memory returned by this function has to be
 * freed by the calling function
 */
char *_getenv(char *path)
{
	char *env_variable;
	char *env_name;
	char *env_value;
	const char *delim = "=";
	int i = 0;

	if (path == NULL || environ == NULL)
		return (NULL);
	while ((env_variable = *(environ + i)) != NULL)
	{
		env_name = _strtok(env_variable, delim);
		if (env_name && _strcmp(env_name, path))
		{
			env_value = _strtok(NULL, delim);
			free(env_name);
			return (env_value);
		}
		free(env_name);
		i++;
	}
	return (NULL);
}
