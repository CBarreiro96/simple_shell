#ifndef _SHELL_H
#define _SHELL_H
#define BUFSIZE 1024
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signum.h>
#include <sys/stat.h>
#include <string.h>

/*To use enviroment variable we need to have this global variable*/
extern char **environ;

int procces(void);

/*Prototipes of memory managment */
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void _memset(char *str, int fill, int n);
void _memcpy(char *dest, char *src, unsigned int bytes);
char *new_memory(char *line, size_t len);
int execut(char **tokens, char **env, char *line, char nline, char **av);
char *_getline(int file);
/*Prototipes of string operation*/
int _strlen_const(const char *s);
void simple_print(const char *str);

#endif /* End of _SHELL_H