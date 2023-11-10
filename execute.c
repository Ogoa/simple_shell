#include "main.h"

/**
 * _execute - Executes a program
 * @argv: An array of pointers to the arguments
 *
 * Return: Nothing
 */
void _execute(char **argv)
{
	pid_t pid;
	char *command_path;
	int wstatus;
	char *one = "./hsh: 1: ", *two = ": not found\n";

	if (argv)
	{
		command_path = get_command(argv[0]);
		if (command_path)
		{
			pid = fork();
			if (pid < 0)
			{
				perror("Failed fork");
				free(command_path);
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				if (execve(command_path, argv, environ) == -1)
				{
					perror("Error:");
					free(command_path);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(&wstatus);
				if (command_path)
					free(command_path);
			}
		}
		else
		{
			write(STDERR_FILENO, _strcat(one, _strcat(argv[0],
							two)), _strlen(one) + _strlen(two) + _strlen(argv[0]));
			exit(127);
		}
	}
}
