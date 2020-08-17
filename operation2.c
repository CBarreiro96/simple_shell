#include "shell.h"
/**
  * _strdup - duplicates a string
  * @src: source to copy from
  * Return: pointer to malloc'd space
  **/
char *_strdup(char *src)
{
	int len, i;
	char *dest;

	if (src == NULL)
		return (NULL);
	len = _strlen(src);
	if (len < 0)
		return (NULL);
	len++;
	dest = malloc((len) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		dest[i] = src[i];
	dest[i - 1] = '\0';
	return (dest);
}
/**
 * _isdigit - checks if chars are digits
 * @c: char to check
 * Return: 1 if yes, 0 if no
 */
int _isdigit(int c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}
/**
 * _atoi - converts a string to an integer
 * @s: the input string
 * Return: the converted int
 */
int _atoi(char *s)
{
	int n, sign, result;

	for (n = result = 0, sign = 1; s[n]; n++)
	{
		if (s[n] == '-')
			sign *= -1;
		if (s[n] >= '0' && s[n] <= '9')
			result = 10 * result - (s[n] - '0');
		if (result < 0 && (s[n] < '0' || s[n] > '9'))
			break;
	}
	if (sign > 0)
		result *= -1;
	return (result);
}
