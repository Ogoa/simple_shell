## Simple Shell
This repository contains files for the group project `0x16. C - Simple shell`<br>
In this project, we implement a simple shell that functions in a similar way to the bash shell. It takes in commands, interpretes them, gives the results and repeats this cycle.<br>
The directory contains several C source files and one header file.


### How does the shell work?
The shell works in a very simple way:
- 1. It prompts the user to enter a command and waits for input from an input stream
- 2. It parses the command string and extracts tokens
- 3. It uses these tokens to find the binary file associated with the command
- 4. It runs the program associated with the command
- 5. It repeats this loop until the user terminates the shell




`main.h`<br>
This header file contains all the function prototypes of functions used across all the source files in this directory.





`getline.c`<br>
This source file contains a custom implementation of the `getline` function provided in the C standard library.<br>
`_getline` reads an entire line of text from an input stream. On success, it returns the number of characters read, otherwise it returns `-1` on failure or upon encountering the `EOF`.<br>
The function prototype is:
```
ssize_t _getline(const char **lineptr, size_t *n, FILE *stream);
```
The function assigns the address of the buffer createdto hold the line that has been read to`lineptr`. `n` indicates the size of the buffer currently pointed to by `lineptr` at the time of the function call. `stream` is a pointer to a stream of the `FILE` structure. This can either be the `stdin` or a text file.





`strtok.c`<br>
This source file contains a custom implementation of the `strtok` function provided in the C standard library.<br>
`_strtok` extracts tokens from a given string (where the tokens are parts of the string that appear in between the specified delimiters). On success, it returns the address of the token otherwise it returns a `NULL` pointer.<br>
The function prototype is:
```
char *_strtok(const char *str, const char *delim);
```
On the first call of `_strtok`, `str` must be a valid pointer (non-null) while on subsequent calls of the function, it should be `NULL`.<br>
`delim` is a string specifying the individual bytes that are delimiters in the initial string passed into the function. `_strtok` maintains an internal state of `str` that was passed into the function at the first call.





`realloc.c`<br>
This source file contains a custom implemetation of the `realloc` function provided in the C standard library.<br>
`_realloc` resizes a given memory block and copies over any existing data from the existing memory block into the new one. On success, it returns the address of the new memory block otherwise on failure `NULL` is returned.<br>
The function prototype is:
```
void *_realloc(void *ptr, size_t old_size, size_t new_size);
```
`ptr` is a pointer to the memory block that is to be resized. `old_size` is the number of bytes `ptr` currently occupies at the time of the function call while `new_size` is the number of bytes you want to resize it to.<br>
If `ptr` is null or `new_size` is `0`, `_realloc` will be equivalent to `malloc`.<br>
If `new_size` is `0`, `_realloc` will be equivalent to `free`.





`strncpy.c`<br>
This source file contains a custom implementation of the `strncpy` function provided int the C standard library.<br>
`_strncpy` copies `n` bytes from one memory block to another memory block.<br>
The function prototype is:
```
void _strncpy(char *dest, const char *src, size_t nmemb);
```
`dest` is a pointer to the memory block where eacah byte contained in `src` is to be copied to, while `nmemb` is the number of bytes to be copied from `src` to `dest`.





`strchr.c`<br>
This source file contains a custom implementation of the `strchr` function provided in the C standard library.<br>
`_strchr` finds the occurrence of a character in a given string. On success, it returns the address of the character in the string, otherwise it returns `NULL` if no match has been found.
The function prototype is:
```
char *_strchr(const char *str, char c);
```
`str` is the string that is being parsed in search of an occurrence of the character `c`.





`strdup.c`
This source file contains a custom implementation of the `strdup` function provided in the C standard library.<br>
`_strdup` creates a duplicate of a string by copying it to a new memory block. On success, the function returns the address to the duplicated string, otherwise `NULL` is returned.<br>
The function prototype is:
```
char *_strdup(const char *str);
```

`str` is the string that is to be duplicated.





`strcat.c`<br>
This source file contains a custom implementation of the native `strcat` function.<br>
`_strcat` concatenates one string to the other. In this context, it was created to dynamically create a new block of memory that can fit both strings involved in this operation.<br>
The function prototype is:
```
char *_strcat(char *dest, const char *src);
```
`src` is the string being appended to `dest`.



`strcmp.c`<br>
This source file contains a custom implementation of the native `strcmp` function.<br>
`_strcmp` compares two strings and evaluates if they are similar or not. If the two are similar, 1 is returned otherwise 0.<br>
The function prototype is:
```
int _strcmp(const char *str1, const char *str2);
```
`str1` and `str2` are the two strings being compared to each other.




`strlen.c`<br>
This source file contains a custom implementation of the native `strlen` function.<br>
`_strlen` evaluates the number of characters making up the string.<br>
The function prototype is:
```
size_t _strlen(const char *str);
```
`str` is the string being evaluated for its length.



`_putchar.c`<br>
This source file contains the implementation of the `putchar` function provided in the C standard library.<br>  
`_putchar` writes an individual character to the standard output on success.<br>
The function prototype is:
```
int _putchar(char c);
```
`c` is the character literal to be printed.




`builtin.c`<br>
This source file contains the implementation of the `builtins` function, which handles the implementation of shell built-in functions.<br>
`builtins` handles the implementation of shell built-in functions

Function Prototype:
```
int builtins(char **argv);
```
`**argv` is the pointer to the array of argument strings




`getenv.c`
This source file contains a custom implementation of the `getenv` function provided in the C standard library.<br>
`_getenv` finds the specified variable among the set environment variables and returns it in the `name=value` format.<br>
The function prototype is:
```
char *_getenv(const char *name);
```
`str` is the NAME of the environment variable you want to find.




`get_command.c`<br>
This source file contains the implementation of `get_command` function that gets the absolute path of a given command and verifies if its binary file exists in the `PATH` variable. It returns a string that is the absolute path to the binary file associated with the command.<br>
It works in a similar way to the native `which` bash command.<br>
The function prototype is:
```
char *get_command(char *command);
```
`command` is the literal shell command being looked for.




`execute.c`<br>
This source file contains a function `_execute` that executes the command by passing the string returned by the `get_command` function, to the `execve`system call to execute the program.<br>
The function prototype is:
```
void _execute(char **argv);
```
`argv` is an array of strings that are tokens extracted from the input command. This array is passed to the `execve`system call.




`free.c`<br>
This source file contains a function `free_arr` that frees dynamically allocated memory from held in an array of pointers.<br>
The function prototype is:
```
void free_arr(char **arr);
```
`arr` is the array of strings.

`strcpy.c`<br>
This source file contains a function `_strcpy` that Copies contents from one memory block to another memory block.<br>
The function prototype is:
```
char *_strcpy(char *dest, const char *src);
```
`dest` is a pointer to the memory address being copied to.
`src` is a pointer to the memory address being copied from.

`_print.c`<br>
This source file contains a function `_print` that prints a string on the standard output stream. 
The function prototype is:
```
size_t _print(const char *str);
```
`str` is the string to be printed.

`pull_request_template.md`<br>
This markdown file contains the commit instructions. It contains a list of requirements that need to be met before a pull request is approved.

`main.c`
This source file contains the `main` function that implements the shell program.
This is the entry point for our shell.
The function prototype is:
```
int main(__attribute__((unused))int argc, char **argv)
```
`argc` is the number of arguments passed to the program in the terminal
`argv` is the array of strings passed as arguments into the program
