#ifndef SHELL_H
#define SHELL_H
#define BUFSIZE 1024
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int procces(void);
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void _memset(char *str, int fill, int n);
void _memcpy(char *dest, char *src, unsigned int bytes);
char *_getline(int file);
int _strlen_const(const char *s);
void simple_print(const char *str);
#endif