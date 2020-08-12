#include "shell.h"
/**
*_getenv - Searches the enviroment variable name
*@name: Varible const type of char to search.
*Return:return a pointer to the corresponding value string.
*/
char *_getenv(const char *name)
{

	int i, j, len;
	char **env, *temporaly;
/*return null if there is no name or if name is NULL*/
	if (!name)
		return (NULL);
/**
* The variable  env is going to use to printf  
*list of enviroment variable */
	env = environ;
/*loop through all existing environment variables*/
	for (i = 0; env[i]; i++)
	{
/*Lenght of name of enviroment variable*/
		for (len = 0; env[i][len] != '='; len++)
			;
		len++;
/*Create a array in memory dinamic to store  the var enviroment*/
		temporaly = malloc((len) * sizeof(char));
/*Store varieble enviroment*/
		_memcpy(temporaly, env[i], len - 1);
		temporaly[len - 1] = '\0';
/*Identify the name*/
		if (_strncmp((char *)name, temporaly, _strlen(temporaly)) == 0)
		{
			free(temporaly);
			temporaly = NULL;
/*Search the name in temporaly*/
			for (j = 0; env[i][j]; j++)
			{
				if (env[i][j] == '=')
				{
					temporaly = &env[i][j + 1];
					break;
				}
			}
			return (temporaly);
		}
		free(temporaly);
		temporaly = NULL;
	}
	return (NULL);
}