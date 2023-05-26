#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} data_of_program;

/**
 * struct builtins - struct for the builtins
 * @builtin: the name of the builtin
 * @function: the associated function to be called for each builtin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;

/* Points to an array of pointers to "environment" strings */
extern char **environ;

typedef struct data
{
	char **agv;
	char *input;
	char **agc;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_lists - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_lists
{
	char separator;
	struct sep_lists *next;
} seplist;

/**
 * struct line_lists - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_lists
{
	char *line;
	struct line_lists *next;
} linelist;

/**
 * struct var_list_s - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct var_list_s
{
	int len_var;
	char *val;
	int len_val;
	struct var_list_s *next;
} var_list;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* --MAIN FUNCTIONS-- */

/* builtins.c */
int (*get_builtIn(char *cmd))(data_shell *datash);

/* builtins2.c */
int builtin_env(data_of_program *data);
int builtin_set_env(data_of_program *data);
int builtin_unset_env(data_of_program *data);

/* builtins3.c */
int builtins_list(data_of_program *data);

/* environment.c */
char *env_get_key(char *key, data_of_program *data);
int env_set_key(char *key, char *value, data_of_program *data);
int env_remove_key(char *key, data_of_program *data);
void print_environ(data_of_program *data);

/* execution.c */
int execute(data_of_program *data);

/* list1.c */
seplist *add_sep_node_end(seplist **head, char sep);
void free_sep_list(seplist **head);
linelist *add_line_node_end(linelist **head, char *line);
void free_line_list(linelist **head);

/* list2.c */
var_list *add_rvar_node(var_list **head, int lvar, char *var, int lval);
void free_rvar_list(var_list **head);

/* main1.c */
char *without_comment(char *in);
void shell_loop(data_shell *datash);

/* main.c */
void free_data(data_shell *datash);
void set_data(data_shell *datash, char **agv);
int main(int agc, char **agv);

/* parsing.c */
void tokenize(data_of_program *data);

/* path_resolution.c */
int check_file(char *full_path);
int find_program(data_of_program *data);
char **tokenize_path(data_of_program *data);
int check_file(char *full_path);

/* Macros */

#define PROMPT "> "

#endif /* SHELL_H */
