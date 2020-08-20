#include "shell.h"
/**
* split_line - splits a line into tokens and stores into a char array
* @nline: the line string to split
*@delimit:It is delimiter about the array.
* Return: the array of pointers
*/
char **split_line(char *nline, char *delimit)
{
	int counter_token = 0, i = 0;
	char **array_of_token, *token, *saveptr;

	if (nline == NULL)
		return (NULL);
	/* This loop iterates the line and outputs the number of tokens in it*/
	while (*(nline + i) != '\0')
	{
		if (nline[i] != ' ' && (nline[i + 1] == ' ' || nline[i + 1] == '\0'
		|| nline[i + 1] == '\t'))
			counter_token++;
		i++;
	}
	array_of_token = malloc(sizeof(char *) * (counter_token + 1));
	if (array_of_token == NULL)
		return (NULL);
	/**
	* Split the line into tokens and return a pointer to the first
	* character of the first token
	**/
	array_of_token[0] = token = _strtok_r(nline, delimit, &saveptr);

	for (i = 1; token; i++)
		array_of_token[i] = token = _strtok_r(NULL, delimit, &saveptr);

	return (array_of_token);
}
