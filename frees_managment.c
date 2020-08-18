#include "shell.h"
/**
 * free_main_memory - free main memory
 * @line:  line entered by user with \n
 * @nline: line entered by user without \n
 * @tokens:line entered by user split it in tokens
 *
 * Return: Void
 */
void free_main_memory(char *line, char *nline, char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens[i]);
	free(tokens);
	free(nline);
	free(line);
}

/**
  * free_linked_list - frees a complety list allocate
  * @head: beginning of the list
  *
  * Return: void
  */
void free_linked_list(env_t *head)
{
	if (head == NULL)
		return;
	free_linked_list(head->next);
	free(head->str);
	free(head);
}

