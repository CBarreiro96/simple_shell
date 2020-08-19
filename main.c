#include "shell.h"
/**
* main - simulate a shell program.
* @ac: the number of arguments passed.
* @av: string of the arguments.
* Return: 0 if is secessful.
*/
int main(int ac, char **av)
{
	char *new_line, **token, *saveptr;
	char *characters = 0;
	env_t *linkedlist_path;
	int counter = 0;

	linkedlist_path = list_from_path();
	if (linkedlist_path == NULL)
		return (-1);
	(void)ac;
	while (1)
	{
		counter++;
		if (isatty(STDIN_FILENO) == 1)
			_prompt("Simple_shell $ ");
		characters = _getline_string(STDIN_FILENO);
		if (characters == NULL)
		{
			free(characters);
			return (127);
		}
		new_line = _strtok_r(characters, "\n;", &saveptr);
		while(new_line)
		{
			token=split_line(new_line,"\t ");
			if (is_builtin(token[0]))
				is_builtin(token[0])(token, linkedlist_path,new_line);
			else
				execut(token, av, linkedlist_path, counter);
			free(token);
			new_line = _strtok_r(NULL, "\n;", &saveptr);
		}
	free(characters);
		
	}
	return (0);
}
