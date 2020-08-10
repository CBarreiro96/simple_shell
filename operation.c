#include "shell.h"
/**
 *
 *
 *
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