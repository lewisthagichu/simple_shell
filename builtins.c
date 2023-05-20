#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * shell_exit - Exit the shell program
 */
void shell_exit(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * shell_env - Print the current environment variables
 */
void shell_env(void)
{
	char **env = environ_ptr();

	while (*env)
	{
	printf("%s\n", *env);
	env++;
	}
}

/**
 * execute_builtin - Execute a built-in command
 * @command: The command to execute
 *
 * Return: 1 if the command is a built-in, 0 otherwise
 */
int execute_builtin(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
	shell_exit();
	return (1);
	}
	else if (strcmp(command, "env") == 0)
	{
	shell_env();
	return (1);
	}

	return (0);
}
