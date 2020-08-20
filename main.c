#include "shell.h"
/**
* main - simulate a shell program.
* @ac: the number of arguments passed.
* @av: string of the arguments.
* Return: 0 if is secessful.
*/
int main(int ac, char **av)
{
	char *line, *new_line, **token;
	size_t size = 0;
	ssize_t characters = 0;
	env_t *linkedlist_path;
	int counter, end = 0;

	linkedlist_path = list_from_path();
	if (linkedlist_path == NULL)
		return (-1);
	(void)ac;
	while (1)
	{
		counter++;
		if (isatty(STDIN_FILENO) == 1)
			_prompt("Simple_shell $ ");
		characters = getline(&line, &size, stdin);
		if (characters == EOF || characters == -1)
		{
			free(line);
			return (end);
		}
		new_line = new_memory(line, characters);
		if (new_line == NULL)
		{
			free(line);
			return (0);
		}
		token = split_line(new_line);
		if (token == NULL)
		{
			free(line), free(new_line);
			return (0);
		}
		if (is_builtin(token[0]))
			is_builtin(token[0])(token, linkedlist_path);
		else
		{
			if (execut(token, av, linkedlist_path, counter, line, new_line) == -1)
				end = 127;
			else
				end = 0;
		}
	}
	free_linked_list(linkedlist_path), free_main_memory(line, new_line, token);
}
