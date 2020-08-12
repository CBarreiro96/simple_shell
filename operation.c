#include "shell.h"
/**
 * simple_print - print a message in the terminal
 * Return: void.
 *
 */
void simple_print(void)
{
	write(STDOUT_FILENO, "Simple_shell $ ",15);

}

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
 * _strlen - replicates strlen from the standard library
 * @s: string to be measured
 * Return: length of string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; *s; s++, i++)
		;
	return (i);
}
/**
 * _strncmp - compares two strings and returns their difference
 * @s1: the first string
 * @s2: the second string
 * @bytes: number of bytes to compare
 * Return: number of bytes that differ
 */
int _strncmp(char *s1, char *s2, size_t bytes)
{
	unsigned int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (i = 0; s1[i] && s2[i] && s2[i] == s1[i] && i < bytes - 1; i++)
		;
	return (s2[i] - s1[i]);
}
