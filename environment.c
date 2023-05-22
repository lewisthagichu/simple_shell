#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include <string.h>

/**
 * get_env_var - Get the value of an environment variable
 * @name: The name of the environment variable
 *
 * Return: The value of the environment variable if found, NULL otherwise
 */
char *get_env_var(char *name)
{
	extern char **environ;
	char **env = environ;
	size_t name_len = strlen(name);

	while (*env)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		return (&(*env)[name_len + 1]);
		env++;
	}

	return (NULL);
}

/**
 * set_env_var - Set the value of an environment variable
 * @name: The name of the environment variable
 * @value: The value to set
 *
 * Return: 0 on success, -1 on failure
 */
int set_env_var(char *name, char *value)
{
	char *var;
	int ret;

	var = malloc(strlen(name) + strlen(value) + 2);
	if (!var)
	{
	perror("malloc");
	return (-1);
	}

	sprintf(var, "%s=%s", name, value);
	ret = putenv(var);

	if (ret != 0)
	perror("setenv");

	return (ret);
}

/**
 * delete_env_var - Delete an environment variable
 * @name: The name of the environment variable to delete
 *
 * Return: 0 on success, -1 on failure
 */
int delete_env_var(char *name)
{
	int ret;

	ret = unsetenv(name);

	if (ret != 0)
	perror("unsetenv");
	return (ret);
}
