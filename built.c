#include "shell.h"
/**
  * is_builtin - checks if cmd is a builtin
  * @cmd: command to find
  * Return: On success - pointer to function, On Failure - NULL pointer
 (* other useful shell builtins:
 (* pwd, echo, pushd, popd, type
 (* * requires ^Z
 (* fg, bg
 (*  * Requires ^Rv
 (* reverse-i-search **HISTORY**
*/
int (*is_builtin(char *cmd))()
{
	unsigned int i;
	builtin_cmds_t builds[] = {
		{"exit", _exit_},
		{NULL, NULL}
	};

	i = 0;
	while (*builds[i].function != NULL)
	{
		if (_strncmp(builds[i].cmd_str, cmd, _strlen(builds[i].cmd_str)) == 0)
			return (builds[i].function);
		i++;
	}


	return (NULL);
}
/**
  * _exit_ - Frees any remaining malloc'd spaces, and exits
  * @linkedlist_path: Linked list to free.
  * @token: Check for other inputs
 (* * CHANGE TO VARIADIC LIST.
  * Return: -1 if exit fails.
  */
int _exit_(char **token, env_t *linkedlist_path, char *new_line)
{
	unsigned char exit_status;
	int i;

	for (i = 0; token[1] && token[1][i]; i++)
	{
		if (!_isdigit(token[1][i]))
		{
			_prompt("numeric argument required, exiting\n");
			break;
		}
	}

	exit_status = token[1] && i >= _strlen(token[1]) ? _atoi(token[1]) : 0;
	if (linkedlist_path && token &&  new_line)
	{
		free_linked_list(linkedlist_path);
		linkedlist_path = NULL;
		free(token);
		token = NULL;
		free(new_line);
		new_line= NULL;
	}
	exit(exit_status);
	return (-1);
}
