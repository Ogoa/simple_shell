#include "main.h"

/**
 * get_command - Gets the absolute path of a given command and verifies
 * if its binary file exists in the PATH variable
 * @command: String representing the command whose absolute path is to
 * be searched for
 *
 * Return: The concatenated string, that is the absolute path to 'command'
 * binary file, otherwise NULL
 * Description: This function works in a similar way to the native
 * 'which' command
 */
char *get_command(char *command)
{
	char *path;
	char *abs_path = NULL;
	const char *delim = ":";
	char *path_dir;
	char *mod_command;
	struct stat status;

	if (command == NULL)
		return (NULL);
	if (stat(command, &status) == 0)
		return (_strdup(command));
	path = _getenv("PATH");
	if (path)
	{
		mod_command = _strcat("/", command);
		path_dir = _strtok(path, delim);
		while (path_dir)
		{
			abs_path = _strcat(path_dir, mod_command);
			if (stat(abs_path, &status) == 0)
			{
				free(mod_command);
				free(path_dir);
				free(path);
				if (access(abs_path, X_OK) == 0)
					return (abs_path);
			}
			if (abs_path)
				free(abs_path);
			free(path_dir);
			path_dir = _strtok(NULL, delim);
		}
		free(mod_command);
		free(path);
	}
	return (NULL);
}
