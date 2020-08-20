#include "shell.h"
/**
* print_errors - Print all posible errors
* @argv:string of the arguments.
* @c:number of time that hsh run.
* @tokens: Command to put error.
* @line: line given for user
* @nline: line without /n
* Return: Void.
*/

void print_errors(char **argv, char **tokens, int c, char *line, char *nline)
{
	char *counter;

	counter = intiger_to_string(c);

	write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, counter, _strlen(counter));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, tokens[0], _strlen(tokens[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
	free(counter);
	free_main_memory(line, nline, tokens);
	exit(0);
}

/**
* intiger_to_string - Print all posible errors
* @c:number of time that hsh run.
*
* Return: a pointer to string number.
*/
char *intiger_to_string(int c)
{
	char *number;
	int ten = 1;
	int temp = c;
	int i = 0;

	number = malloc(sizeof(char) * 50);
	if (number == NULL)
		return (NULL);

	c = c / 10;

	while (c != 0)
	{
		c = c / 10;
		ten = ten * 10;
	}

	while (ten != 0)
	{

		number[i] = (temp / ten) + '0';
		temp = temp % ten;
		ten = ten / 10;
		i++;
	}
	number[i] = '\0';
	return (number);
}
