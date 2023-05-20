#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * print_error - Print an error message
 * @msg: The error message to print
 */
void print_error(char *msg)
{
	perror(msg);
}

/**
 * print_env - Print the current environment variables
 */
void print_env(void)
{
	char **env = environ_ptr();

	while (*env)
	{
	printf("%s\n", *env);
	env++;
	}
}

/**
 * change_directory - Change the current working directory
 * @path: The path of the directory to change to
 *
 * Return: 0 on success, -1 on failure
 */
int change_directory(char *path)
{
	int ret;

	ret = chdir(path);
	if (ret == -1)
	print_error("cd");

	return (ret);
}
