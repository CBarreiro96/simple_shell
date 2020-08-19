#include "shell.h"
/**
* split_line - splits a line into tokens and stores into a char array
* @nline: the line string to split
* Return: the array of pointers
*/
char **split_line(char *nline)
{
	int counter_token = 0, i = 0;
	char **array_of_token, *token, *tokencopy;

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
	token = strtok(nline, DELIMS);
	/**
	* This loop copies the content of each token and stores the one-touch
	* content in one of the previously pointers.
	**/
	for (i = 0 ; token != NULL ; i++)
	{
		tokencopy = copy_token(token);
		if (tokencopy == NULL)
		{
			free(array_of_token);
			return (NULL);
		}
		*(array_of_token + i) = tokencopy;
		token = strtok(NULL, DELIMS);
	}

	*(array_of_token + i) = NULL;

	return (array_of_token);
}
