#include "shell.h"
/**
 * _prompt - print a prompt in the terminal
 * @str: is a message that print
 * Return: void.
 *
 */
void _prompt(char *str)
{
	int len;

	len = _strlen(str);
	write(STDOUT_FILENO, str, len);

}
/**
 * execut - searh and execute binary locate in PATH
 * @tokens: line entered by user split it in tokens
 * @av: name of the executable
 * @linkedlist_path: current enviroment
 * @c:number of time that hsh run.

 * Return: 0 if success -1 if fail
 */
int execut(char **tokens, char **av, env_t *linkedlist_path, int c)
{
	pid_t m_PID;
	char *abs_path;

	if (tokens == NULL || *tokens == NULL)
		return (-1);

	if (av == NULL || *av == NULL)
		return (-1);

	abs_path = search_os(tokens[0], linkedlist_path);


	m_PID = fork();

	if (m_PID == -1)
	{
		write(STDOUT_FILENO, "Error in fork", 13);
		return (-1);
	}

	else if (m_PID == 0)
	{
		if (execve(abs_path, tokens, environ) == -1)
			print_errors(av, tokens, c);
		return (0);
	}

	else
		wait(NULL);

	free(abs_path);

	return (0);
}
