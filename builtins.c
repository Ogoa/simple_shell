#include "main.h"

/**
 * check_builtin - Checks if the command given is a shell bult-in
 * and executes it if a match is found
 * @argv: Pointer to the array of arguments passed into the program
 *
 * Return: 1 if the arguments passed is a shell built-in command, otherwise 0
 * Description: If argv[0] is a shell built-in, the relevant function is
 * executed and this function returns 1
 */
int check_builtin(char **argv, char **lineptr)
{
	void (*func)(char **argv, char **environ);

	if (_strcmp(argv[0], "exit"))
		free(*lineptr); /* Taking care of memory leaks */
	func = get_builtin(argv[0]);
	if (func == NULL)
	{
		return (0);
	}
	else
	{
		func(argv, environ);
		return (1);
	}
}

/**
 * get_builtin - Maps a built-in command to its function
 * @command: Pointer to the first string in the argument array
 *
 * Return: Pointer to the relevant function that maps to 'command'
 */
void (*get_builtin(const char *command))(char **argv, char **environ)
{
	builtins types[] = {
		{"exit", _exit_},
		{"cd", _cd},
		{"env", _env},
		{NULL, NULL}
	};
	int i = 0;

	while (types[i].cmd)
	{
		if (_strcmp(command, types[i].cmd))
			return (types[i].func);
		i++;
	}
	return (NULL);
}

/**
 * _exit_ - Exits the shell
 * @argv: Pointer to the array of arguments passed into the shell
 * @environ: Pointer to the array of environment variables
 *
 * Return: Nothing
 */
void _exit_(char **argv, __attribute__((unused))char **environ)
{
	free_arr(argv);
	exit(EXIT_SUCCESS);
}

/**
 * _cd - Changes directory
 * @argv: Pointer to the array of arguments passed into the shell
 * @environ: Pointer to the array of environment variables
 *
 * Return: Nothing
 */
void _cd(char **argv, __attribute__((unused))char **environ)
{
	if (argv[1] == NULL)
		chdir(_getenv("HOME"));
	else
		chdir(argv[1]);
}

/**
 * _env - Prints out all the environment variables
 * @argv: Pointer to the array if arguments passed into the shell
 * @environ: Pointer to the array of environment variables
 *
 * Return: Nothing
 */
void _env(__attribute__((unused))char **argv, char **environ)
{
	int i = 0;

	while (*(environ + i))
	{
		printf("%s\n", *(environ + i));
		i++;
	}
}
