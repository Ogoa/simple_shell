#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

extern char **environ;

/* Functions used to print strings */
int _putchar(char c);
size_t _print(const char *str);

/* Custom implementation of native C functions */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
size_t _strlen(const char *str);
char *_strncpy(char *dest, const char *src, size_t nmemb);
char *_strchr(const char *str, int c);
char *_strdup(const char *str);
char *_strtok(char *str, const char *delim);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);

/* Free an array of pointers */
void free_arr(char **arr);

/* Execute the program */
void _execute(char **argv);

/* Get the absolute path for a command */
char *get_command(char *command);
char *_getenv(char *path);

/**
 * struct bultins - A structure representing a key-value pair of a
 * command and the pointer to the function it maps to
 * @cmd: The specific command
 * @func: Pointer to th builtin function the command maps to
 *
 * Description :This key-value pair represents a shell built-in
 * command and the function that will be invoked to execute it
 */
typedef struct builtins
{
	char *cmd;
	void (*func)(char **, char **);
} builtins;
/* Builtin commands */
int check_builtin(char **argv, char **lineptr);
void (*get_builtin(const char *command))(char **argv, char **environ);
void _exit_(char **argv, char **environ);
void _env(char **argv, char **environ);
void _cd(char **argv, char **environ);

#endif /* ifndef MAIN_H */
