#include "main.h"

/**
 * main - Implement a simple shell program
 * @argc: Number of arguments passed to the program in the terminal
 * @argv: Array of strings passed as arguments into the program
 *
 * Return: Always 0 (Successful exit)
 */
int main(__attribute__((unused))int argc, char **argv)
{
	char *prompt = "($) ";
	char *lineptr;
	int i = 0;
	size_t n = 0;
	char *token;
	int token_count = 0;
	const char *delim = " \n";

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", prompt);
		if (_getline(&lineptr, &n, stdin) == -1)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		token = _strtok(lineptr, delim);
		while (token)
		{
			token_count++;
			free(token);
			token = _strtok(NULL, delim);
		}
		argv = malloc(sizeof(char *) * (token_count + 1));
		if (argv == NULL)
			return (-1);
		token = _strtok(lineptr, delim);
		i = 0, token_count = 0;
		while (token)
		{
			argv[i++] = _strdup(token);
			free(token);
			token = _strtok(NULL, delim);
		}
		argv[i] = NULL;
		if (check_builtin(argv, &lineptr))
		{
			free_arr(argv);
			continue;
		}
		_execute(argv);
		free_arr(argv);
	}
	free(lineptr);
	return (0);
}
