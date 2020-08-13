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
int execut(char **tokens, char **env, char *line, char *nline, char **av)
{
	pid_t m_PID;
	struct stat status;


	/* validations of parameters */
	if (tokens == NULL || *tokens == NULL) 
		return (-1);
	
	if (av == NULL || *av == NULL)
		return (-1);
	
	if (env == NULL || *env == NULL)
		return (-1);

	/* start with the child proccess */
	m_PID = fork(); 

	/* verification child proccess */
	if (m_PID == -1) 
	{
		write(STDOUT_FILENO, "Error in fork", 13);
		return (-1);
		printf("%s",line);
		printf("%s",nline);
	}
	
	/*execution of child proccess */ 
	else if (m_PID == 0)
	{
		if (tokens[0][0] == '/')
		{
			if(stat(tokens[0], &status) == -1)
			{
					print_errors(av, tokens);
			}
			execve(tokens[0],tokens, NULL);
		}

		
		return 0;
	}

	else
		wait(NULL);

	return (0);
}


