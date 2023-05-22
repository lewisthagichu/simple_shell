#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * resolve_path - Resolve the full path of an executable using the PATH variable
 * @command: The command to resolve
 *
 * Return: The full path of the executable if found, NULL otherwise
 */
char *resolve_path(char *command)
{
char *path = get_env_var("PATH");
char *path_copy = strdup(path);
char *token, *full_path;
char *delimiters = ":";

if (!path || !path_copy)
return (NULL);

token = strtok(path_copy, delimiters);
while (token)
{
	full_path = malloc(strlen(token) + strlen(command) + 2);
	if (!full_path)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	sprintf(full_path, "%s/%s", token, command);

	if (access(full_path, F_OK) == 0)
	{
		free(path_copy);
		return (full_path);
	}

	free(full_path);
	token = strtok(NULL, delimiters);
	}

	free(path_copy);
	return (NULL);
}
