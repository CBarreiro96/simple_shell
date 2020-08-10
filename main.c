#include "shell.h"
/**
 * main - simula a shell program.
 * @ac: the number of arguments passed.
 * @av: string of the arguments.
 * @env: current envitoment.
 *
 * Return: 0 if is secessful.
 */
int main(int ac, char **av, char **env);
{
	char *line, *new_line;
	size_t size = 0;
	size_t characters;
	char *token;
	const char s[2] = " ";

	(void)ac;
	(void)av;

	while (1)
	{
		simple_print(); /* print $ */

		character = getline(&line, &size, stdin); /* get line */
		if (characters == EOF || characters == -1)
		{
			free(line);
			return (0);
		}

		new_line = new_memory(line, characters); /* get line without \n */
		if (new_line == NULL)
		{
			free(line);
			return (0);
		}

		token = strtok(str, s); /*split the line in tokens */
		if (token == NULL)
		{
			free(line);
			free(new_line);
			return (0);
		}
		while (token != NULL)
			token = strtok(NULL, s);


		execut(token, env, line, nline, av);

	}
	return (0);

}
