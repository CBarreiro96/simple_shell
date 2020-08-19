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
	free_tokens(tokens);
	free(line);
	line=NULL;
	free(nline);
	nline=NULL;
	free(tokens);
	tokens= NULL;
}

/**
  * free_linked_list - frees a complety list allocate
  * @head: beginning of the list
  *
  * Return: void
  */
void free_linked_list(env_t *head)
{
	env_t *nextnode;

	while (head != NULL)
	{
		nextnode = head->next;
		free(head->str);
		free(head);
		head = nextnode;
	}
}
/**
  * free_tokens - free all tokens
  * @tokens: beginning of the list
  *
  * Return: void
  */

void free_tokens(char **tokens)
{

	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens[i]);
}
