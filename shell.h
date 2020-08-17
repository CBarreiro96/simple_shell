#ifndef _SHELL_H
#define _SHELL_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <string.h>
#define BUFSIZE 1024
#define DELIMS " \t\0"
/*To use enviroment variable we need to have this global variable*/
extern char **environ;
/**
 * struct environ_type - struct for linked list PATH
 * @str: a node
 * @len: size of node
 * @next: next node
 *
 */
typedef struct environ_type
{
	char *str;
	unsigned int len;
	struct environ_type *next;
} env_t;
/**
* struct builtin_commands - stuct for function pointers to builtin commands
* @cmd_str: commands (env, cd, alias, history)
* @function: function
*/
typedef struct builtin_commands
{
	char *cmd_str;
	int (*function)();
} builtin_cmds_t;

char *_strdup(char *src);
env_t *add_node(env_t **head, char *str, unsigned int len);
env_t *list_from_path(void);
env_t *environ_linked_list(void);
char *search_os(char *cmd, env_t *linkedlist_path);
char *_getenv(const char *name);
char *_strcat_realloc(char *dest, char *src);
void free_list(env_t *head);
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void _memset(char *str, int fill, int n);
void _memcpy(char *dest, char *src, unsigned int bytes);
char *new_memory(char *line, size_t len);
int execut(char **tokens, char **av, env_t *linkedlist_path);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, size_t bytes);
int _strlen_const(const char *s);
void simple_print(void);
char **split_line(char *nline);
char *copy_token(char *nline);
void print_errors(char **argv, char **tokens);
void free_main_memory(char *line, char *nline, char **tokens);
void free_linked_list(env_t *head);
int (*is_builtin(char *cmd))();
int _exit_(char **tokens, env_t *linkedlist_path);
int _atoi(char *s);
int _isdigit(int c);

#endif /* End of _SHELL_H */
