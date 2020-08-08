#include "shell.h"

/**
 * _strlen_const - strlen for const strings
 * @s: string to be measured
 * Return: length of string
 */
int _strlen_const(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
/**
 * simple_print - allows us to print simple lines
 * @str: const string to print
 */
void simple_print(const char *str)
{
	int len;

	len = _strlen_const(str);
	write(STDOUT_FILENO, str, len);
}