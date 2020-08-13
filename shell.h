#ifndef _SHELL_H
#define _SHELL_H
#define BUFSIZE 1024
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <string.h>
#define DELIMS " \t\0"

/*To use enviroment variable we need to have this global variable*/
extern char **environ;


typedef struct environ_type
{
	char *str;
	unsigned int len;
	struct environ_type *next;
} env_t;

char *_strdup(char *src);
env_t *add_node(env_t **head, char *str, unsigned int len);
env_t *list_from_path(void);
env_t *environ_linked_list(void);
char *search_os(char *cmd, env_t *linkedlist_path);
char *_getenv(const char *name);
char *_strcat_realloc(char *dest, char *src);
void free_list(env_t *head);
/*Prototipes of memory managment */
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void _memset(char *str, int fill, int n);
void _memcpy(char *dest, char *src, unsigned int bytes);
char *new_memory(char *line, size_t len);
int execut(char **tokens, env_t *linkedlist_path);

int _strlen(char *s);
int _strncmp(char *s1, char *s2, size_t bytes);

/*Prototipes of string operation*/
int _strlen_const(const char *s);
void simple_print(void);
char **split_line(char *nline);
char *copy_token(char *nline);

#endif /* End of _SHELL_H */