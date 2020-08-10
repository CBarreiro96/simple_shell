#include "holberton.h"
/**
 * _realloc_newline - allocad a copy of line without \n.
 * @line: the original line got it.
 * @len: the number of characters
 *
 * Return: a copy a new line with \0.
 */
char *_realloc_newline(char *line, size_t len)
{
	char *newline;
	int i =  0;

	newline = malloc(sizeof(char) * len);
	if (newline == NULL)
		return (NULL);

	while (*(line + i) != '\n')
	{
		*(newline + i) = *(line + i);
		i++;
	}

	*(newline + i) = '\0';

	return (newline);

}

