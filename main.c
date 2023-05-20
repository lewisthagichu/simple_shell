/**
 * main - Entry point of the shell program
 *
 * Description: This program implements a simple shell where it displays a
 * prompt, reads user input, and executes commands entered by the user. It
 * supports basic functionality such as executing built-in commands, handling
 * the "exit" command, and displaying the
 * prompt again after executing a command.
 * It also handles the end-of-file condition (Ctrl+D) and displays an error
 * message if there's an error executing a command.
 *
 * Return: Always returns 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_INPUT_LENGTH 1024

int main(void)
{
	char input[MAX_INPUT_LENGTH];
	int status;

	while (1)
	{
		printf("$ ");

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("fgets");
				exit(EXIT_FAILURE);
			}
		}

		input[strcspn(input, "\n")] = '\0';

		if (input[0] == '\0')
			continue;

		status = execute_command(input);
		if (status == -1)
		{
			fprintf(stderr, "Error executing the command.\n");
			exit(EXIT_FAILURE);
		}
	}

	return (EXIT_SUCCESS);
}
