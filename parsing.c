#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * tokenize_input - Tokenize the input command into arguments
 * @input: The input command string
 *
 * Return: An array of pointers to the arguments
 */
char **tokenize_input(char *input)
{
	const char *delimiters = " \t\n";
	char **tokens = NULL;
	char *token;
	int num_tokens = 0;

	token = strtok(input, delimiters);
	while (token)
	{
	num_tokens++;
	tokens = realloc(tokens, sizeof(char *) * num_tokens);

	if (tokens == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}

	tokens[num_tokens - 1] = token;
	token = strtok(NULL, delimiters);
	}

	num_tokens++;
	tokens = realloc(tokens, sizeof(char *) * num_tokens);
	if (tokens == NULL)
	{
	perror("realloc");
	exit(EXIT_FAILURE);
	}
	tokens[num_tokens - 1] = NULL;

	return (tokens);
}

/**
 * free_tokens - Free the memory allocated for the token array
 * @tokens: The array of tokens
 */
void free_tokens(char **tokens)
{
	if (tokens)
	free(tokens);
}
