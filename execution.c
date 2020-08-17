#include "shell.h"
/**
 * simple_print - print a prompt in the terminal
 * Return: void.
 *
 */
void _prompt(const char *str)
{
	int len;

	len = _strlen_const(str);
	write(STDOUT_FILENO, str, len);

}
/**
 * execut - searh and execute binary locate in PATH
 * @tokens: line entered by user split it in tokens
 * @av: name of the executable
 * @linkedlist_path: current enviroment
 *
 * Return: 0 if success -1 if fail
 */
int execut(char **tokens, char **av, env_t *linkedlist_path)
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
			print_errors(av, tokens);
		return (0);
	}

	else
		wait(NULL);

	free(abs_path);

	return (0);
}
