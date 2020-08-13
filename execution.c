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
int execut(char **tokens, char **av, env_t *linkedlist_path)
{
	pid_t m_PID;
	char *abs_path;

	abs_path = search_os(tokens[0], linkedlist_path);


	/* validations of parameters */
	if (tokens == NULL || *tokens == NULL) 
		return (-1);
	
	if (av == NULL || *av == NULL)
		return (-1);
	

	/* start with the child proccess */
	m_PID = fork(); 

	/* verification child proccess */
	if (m_PID == -1) 
	{
		write(STDOUT_FILENO, "Error in fork", 13);
		return (-1);
	}
	
	/*execution of child proccess */ 
	else if (m_PID == 0)
	{
		if (execve(abs_path, tokens, environ) == -1)
			print_errors(av, tokens);
		return 0;

	}

	else
		wait(NULL);

	return (0);
}


