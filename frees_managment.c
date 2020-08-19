#include "shell.h"
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
