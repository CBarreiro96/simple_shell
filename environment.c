#include "shell.h"
/**
* list_from_path - builds a linked list from PATH
* Return: pointer to linked list
*/
env_t *list_from_path(void)
{
	unsigned int len, i, j;
	char *env;
	char buffer[BUFSIZE];
	env_t *ep;

	ep = NULL;
	len = i = j = 0;

	env = _getenv("PATH");
	if (env == NULL)
		return (NULL);

	while (*env)
	{
		buffer[j++] = *env;
		len++;

		if (*env == ':')
		{
			len--;
			buffer[j - 1] = '/';
			buffer[j] = '\0';
			add_node(&ep, buffer, len);
			len = j = 0;
		}
		env++;
	}
	return (ep);
}
/**
  * environ_linked_list - builds a linked list from PATH
  * Return: pointer to linked list
  */
env_t *environ_linked_list(void)
{
	int i, j;
	char **env;
	env_t *ep;

	ep = NULL;
	i = j = 0;
	env = environ;
	while (env[i])
	{
		add_node(&ep, env[i], (unsigned int)_strlen(env[i]));
		i++;
	}
	return (ep);
}

/**
  * search_os - search through os to find a command
  * @tokens: command to search for
  * @linkedlist_path: path to search through
  * Return: String to absolute path if found, NULL if not
  */
char *search_os(char *tokens, env_t *linkedlist_path)
{
	int status;
	char *step_abs_path;
	env_t *path_node;

	path_node = linkedlist_path;
	if (path_node == NULL || tokens == NULL)
		return (NULL);

	if ((_strncmp(tokens, "/", 1) == 0
			|| _strncmp(tokens, "./", 2) == 0)
			&& access(tokens, F_OK | X_OK) == 0)
	{
		step_abs_path = tokens;
		if (step_abs_path == NULL)
			return (NULL);

		return (step_abs_path);
	}

	while (path_node != NULL)
	{
		step_abs_path = _strdup(path_node->str);
		if (step_abs_path == NULL)
			return (NULL);

		step_abs_path = _strcat_realloc(step_abs_path, tokens);
		if (step_abs_path == NULL)
			return (NULL);

		status = access(step_abs_path, F_OK | X_OK);
		if (status == 0)
			return (step_abs_path);
		free(step_abs_path);
		path_node = path_node->next;
	}
	return (NULL);
}
