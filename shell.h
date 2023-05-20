#ifndef SHELL_H
#define SHELL_H

/* Function Declarations */

/* main.c */
void display_prompt(void);
char *read_command(void);

/* shell.c */
void execute_command(char *command);

/* utilities.c */
void handle_error(char *message);

/* input.c */
char **tokenize_input(char *input);
void free_tokens(char **tokens);

/* execution.c */
void execute_external_command(char **args);
void execute_builtin_command(char **args);

/* builtins.c */
void shell_exit(void);
void shell_env(void);
int execute_builtin(char *command);

/* environment.c */
char *get_env_var(char *name);
int set_env_var(char *name, char *value);
int delete_env_var(char *name);

/* parsing.c */
char **tokenize_input(char *input);
void free_tokens(char **tokens);

/* path_resolution.c */
char *resolve_path(char *command);

/* Macros */

#define PROMPT "> "

#endif /* SHELL_H */
