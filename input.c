#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

#define MAX_INPUT_LENGTH 1024

/**
 * read_input - Read user input from stdin
 *
 * Return: The input string on success, NULL on failure or end-of-file
 */
char *read_input(void)
{
char *input = NULL;
ssize_t input_size = 0;

if (getline(&input, &input_size, stdin) == -1)
{
	if (feof(stdin))
	{
		free(input);
		return (NULL);
	}
	else
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
}

input[strcspn(input, "\n")] = '\0';
return (input);
}

/**
 * process_input - Process the user input
 * @input: The input string
 *
 * Return: The processed input string
 */
char *process_input(char *input)
{
    /* Add any additional processing logic here if needed */
	return (input);
}
