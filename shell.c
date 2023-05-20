#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

#define MAX_ARGS 64

/**
 * execute_command - Execute a command in the shell
 * @command: The command to execute
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *command)
{
	char *args[MAX_ARGS];
	char *token;
	int i = 0;
	pid_t child_pid, wait_pid;
	int status;

	/* Tokenize the command */
	token = strtok(command, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;

	/* Fork a child process */
	child_pid = fork();
	if (child_pid < 0)
	{
		perror("fork");
		return -1;
	}

	if (child_pid == 0)
	{
		/* Child process */
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
			wait_pid = waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 0;
}
