#include "shell.h"
/**
 * execut - execute the comamts.
 * @tokens: the tokens of a line.
 * @env: current enviroment.
 * @line: first line with \n.
 * @nline: copy the first line without \n.
 * Return: 0 if success -1 if fail.
 */
<<<<<<< HEAD
int execut(char **tokens, char **av, env_t *linkedlist_path)
{
	pid_t m_PID;
	char *abs_path;

	abs_path = search_os(tokens[0], linkedlist_path);

=======
int execut(char **tokens, env_t *linkedlist_path)
{
	pid_t m_PID;
	struct stat status;
    char *abs_path;

	abs_path = search_os(tokens[0], linkedlist_path);
>>>>>>> e2c77fcf300b7d5bdb4683b8a0a90ca746ad89c0

	/* validations of parameters */
	if (tokens == NULL || *tokens == NULL) 
		return (-1);
	
<<<<<<< HEAD
	if (av == NULL || *av == NULL)
		return (-1);
	
=======

>>>>>>> e2c77fcf300b7d5bdb4683b8a0a90ca746ad89c0

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
<<<<<<< HEAD
			print_errors(av, tokens);
=======
			perror("execution failed\n");
>>>>>>> e2c77fcf300b7d5bdb4683b8a0a90ca746ad89c0
		return 0;

	}

	else
		wait(NULL);

	return (0);
}


