#ifndef SHELL_H
#define SHELL_H

/* Function Declarations */

/* main.c */
void display_prompt(void);
char *read_command(void);

/* shell.c */
int execute_command(char *command);

/* utilities.c */
void print_error(char *message);
void print_env(void);
int change_directory(char *path);

/* input.c */
char *read_input(char *void);
void *process_input(char *input);

/* execution.c */
int execute_command(char *command);

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
