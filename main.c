#include "main.h"

int token_counter(char **lineptr);

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
			_print(prompt);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		token_count = token_counter(&lineptr);
		if (!token_count)
			continue;
		argv = malloc(sizeof(char *) * (token_count + 1));
		if (argv == NULL)
			return (-1);
		token = strtok(lineptr, delim);
		i = 0, token_count = 0;
		while (token)
		{
			argv[i++] = strdup(token);
			/*free(token);*/
			token = strtok(NULL, delim);
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

/**
 * token_counter - Evaluates the number of tokens in the command string
 * @lineptr: Pointer to the string containing the command passed to the
 * shell
 *
 * Return: The number of tokens in the command
 */
int token_counter(char **lineptr)
{
	int token_count = 0;
	char *token;
	const char *delim = " \n";
	char *lineptr_cpy = *lineptr;

	if (lineptr == NULL || *lineptr == NULL)
		return (0);
	token = strtok(lineptr_cpy, delim);
	while (token)
	{
		token_count++;
		/*free(token);*/
		token = strtok(NULL, delim);
	}
	return (token_count);
}
