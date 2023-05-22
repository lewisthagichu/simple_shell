#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

/**
 * execute_command - Execute a non-built-in command
 * @command: The command to execute
 *
 * Return: 0 on success, -1 on error
 */
int execute_command2(char **command)
{
	if (strcmp(command[0], "exit") == 0)
	{
	shell_exit();
	return (0);
	}

	return (-1);
}

/**
 * execute_command - Execute a command in the shell
 * @command: The command to execute
 *
 * Return: 0 on success, -1 on failure
 */
int execute_external_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		/* Child process */
		char *args[4];
		args[0] = "/bin/sh";
		args[1] = "-c";
		args[2] = command;
		args[3] = NULL;

		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		do {
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("waitpid");
				return (-1);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}

