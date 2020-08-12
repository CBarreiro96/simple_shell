#include "shell.h"
/**
 * main - simula a shell program.
 * @ac: the number of arguments passed.
 * @av: string of the arguments.
 * @env: current envitoment.
 *
 * Return: 0 if is secessful.
 */
int main(int ac, char **av, char **env)
{
	char *line, *new_line;
	size_t size = 0;
	ssize_t characters;
	char *token;

	(void)ac;
	(void)av;

	while (1)
	{
		 /* print $ */
		simple_print();

		 /* get line */
		characters = _getline(STDIN_FILENO);
		if (characters == EOF || characters == -1)
		{
			free(line);
			return (0);
		}
		/* get line without \n */
		new_line = new_memory(line, characters); 
		if (new_line == NULL)
		{
			free(line);
			return (0);
		}
		 /*split the line in tokens */
		token = strtok(new_line, DELIMS);
		if (token == NULL)
		{
			free(line);
			free(new_line);
			return (0);
		}

		execut(token, env, line, new_line, av);

	}
	return (0);

}
