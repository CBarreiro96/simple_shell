#include "shell.h"
/**
 * main - simula a shell program.
 * @ac: the number of arguments passed.
 * @av: string of the arguments.
 * @env: current envitoment.
 *
 * Return: 0 if is secessful.
 */
int main(int ac, char **av)
{
	char *line, *new_line;
	size_t size = 0;
	ssize_t characters;
    env_t *linkedlist_path;
	char **token;
	env_t *linkedlist_path;
	linkedlist_path = list_from_path();

	(void)ac;
    linkedlist_path = list_from_path();
	while (1)
	{
		/* test whether a file descriptor refers to a terminal */
		if (isatty(STDIN_FILENO) == 1)
			simple_print();

		 /* get line */
		characters = getline(&line, &size, stdin);
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
		 /*split the line in tokens, in the heap alloc a array of tokens*/
		token = split_line(new_line);
		if (token == NULL)
		{
			free(line);
			free(new_line);
			return (0);
		}

		execut(token, av, linkedlist_path);


	}
	return (0);

}
