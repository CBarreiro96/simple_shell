#include "shell.h"
/**
 * split_line - splits a line into tokens and stores into a char array
 * @nline: the line string to split
 *
 * Return: the array of pointers
 */
char **split_line(char *nline)
{

	int i = 0;
	int counter_token = 0;
	char **array_of_token;
	char *token, *tokencopy;

	if (nline == NULL)
		return (NULL);
	/* This loop iterates the line and outputs the number of tokens in it*/
	while (*(nline + i) != '\0')
	{
		if (nline[i] != ' ' && (nline[i + 1] == ' ' || nline[i + 1] == '\0'))
			counter_token++;
		i++;
	}

	i = 0;
	/**
	* Allocate memory in the heap for the number of tokens obtained + 1.
	* this is pointer array. Example 3 tokens found = 3 pointers created in the heap.
	**/
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
	while (token != NULL)
	{
		/**
		* The copy_token function copies the token to which the token
		* pointer is currently pointing.
		**/
		tokencopy = copy_token(token);
		if (tokencopy == NULL)
		{
			free(array_of_token);
			return (NULL);
		}
		*(array_of_token + i) = tokencopy;
		token = strtok(NULL, DELIMS);
		i++;
	}
	*(array_of_token + i) = NULL;
	return (array_of_token);
}
