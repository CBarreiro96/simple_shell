#include "shell.h"
/**
 * execut - execute the comamts.
 * @tokens: the tokens of a line.
 * @env: current enviroment.
 * @line: first line with \n.
 * @nline: copy the first line without \n.
 *
 * Return: 0 if success -1 if fail.
 */
int execut(char *tokens, char **env, char *line, char *nline, char **av)
{
	pid_t m_PID;
	//struct stat status;

	if (tokens == NULL) /* validations of parameters */
		return (-1);
	
	if (av == NULL || *av == NULL)
		return (-1);
	
	if (env == NULL || *env == NULL)
		return (-1);

	m_PID = fork(); /* start with the child proccess */

	if (m_PID == -1) /* verification child proccess */
	{
		write(STDOUT_FILENO, "Error in fork", 13);
		return (-1);
	}

	else if (m_PID == 0) /*execution of child proccess */ 
	{
		printf("%d",*line);
		printf("%d",*nline);
		return 0;
	}

	else
		wait(NULL);

	return (0);
}


