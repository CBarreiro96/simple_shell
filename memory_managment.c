#include "shell.h"
/**
 * _realloc - reallocates memory based on inputs
 * @ptr: pointer to original memory address
 * @old_size: old memory size
 * @new_size: new memory size
 * Return: new memory address
 */

void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *tmp, *buff;
	unsigned int i;

	if (ptr == NULL)
	{
		buff = malloc(new_size);
		if (buff == NULL)
			return (NULL);
		return (buff);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		buff = malloc(new_size * sizeof(char));
		tmp = ptr;

		_memset(buff, '\0', new_size);
		for (i = 0; i < old_size; i++)
			buff[i] = tmp[i];
		free(ptr);
		return (buff);
	}
	return (ptr);
}
/**
 * _memset - fills a given string with n number of fill chars
 * @str: string to be filled with fill
 * @fill: the char to put into str
 * @n: the number of chars to fill
 */
void _memset(char *str, int fill, int n)
{
	int i;

	for (i = 0; i < n; i++)
		str[i] = fill;
}
/**
 * _memcpy - copies part or all of string src to string dest
 * @dest: destination string
 * @src: source string
 * @bytes: number of bytes to copy
 */
void _memcpy(char *dest, char *src, unsigned int bytes)
{
	unsigned int i;

	for (i = 0; i < bytes; i++)
		dest[i] = src[i];
}
/**
 * new_memory - allocad a copy of line without \n.
 * @line: the original line got it.
 * @len: the number of characters
 * Return: a copy a new line with \0.
 */
char *new_memory(char *line, size_t len)
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
/**
 *copy_token - returns pointer to allocated space containing copy of string
 *@nline: string that will be copied into the space
 *Return: pointer to allocated space
 */
char *copy_token(char *nline)
{
	int i, size;
	char *line;

	i = 0;
	size = 0;

	if (nline == NULL)
		return (NULL);

	while (*(nline + i) != '\0')
	{
		size++;
		i++;
	}

	i = 0;
	line = malloc(sizeof(char) * size + 1);

	if (nline == NULL)
		return (NULL);

	while (*(nline + i) != '\0')
	{
		*(line + i) = *(nline + i);
		i++;
	}
	*(line + i) = '\0';
	return (line);
}
