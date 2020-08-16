#include "shell.h"
/**
* print_errors - Print all posible errors
* @argv:string of the arguments.
* @tokens: Command to put error.
* Return: Void.
*/
void print_errors(char **argv, char **tokens)
{
	write(STDOUT_FILENO, argv[0], _strlen_const(argv[0]));
	write(STDOUT_FILENO, ": 1: ", 5);
	write(STDOUT_FILENO, tokens[0], _strlen_const(tokens[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
