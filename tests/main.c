#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <string.h>
#define BUFSIZE 1024
#define DELIMS " \t\0"
/*To use enviroment variable we need to have this global variable*/
extern char **environ;
/**
* struct environ_type - linked list from PATH
* @str: path in the format /usr/bin
* @len: length of the string
* @next: points to the next node
*/
typedef struct environ_type
{
	char *str;
	unsigned int len;
	struct environ_type *next;
} env_t;
/**
* struct builtin_commands - stuct for function pointers to builtin commands
* @cmd_str: commands (env, cd, alias, history)
* @function: function
*/
typedef struct builtin_commands
{
	char *cmd_str;
	int (*function)();
} builtin_cmds_t;

char *_strdup(char *src);
env_t *add_node(env_t **head, char *str, unsigned int len);
env_t *list_from_path(void);
env_t *environ_linked_list(void);
char *search_os(char *cmd, env_t *linkedlist_path);
char *_getenv(const char *name);
char *_strcat_realloc(char *dest, char *src);
void free_list(env_t *head);
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void _memset(char *str, int fill, int n);
void _memcpy(char *dest, char *src, unsigned int bytes);
char *new_memory(char *line, size_t len);
int execut(char **tokens, char **av, env_t *linkedlist_path, int c, char *line, char *nline);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, size_t bytes);
void _prompt(void);
char **split_line(char *nline);
char *copy_token(char *nline);
void print_errors(char **argv, char **tokens, int c, char *line, char *nline);
void free_main_memory(char *line, char *nline, char **tokens);
void free_linked_list(env_t *head);
int (*is_builtin(char *cmd))();
int _exit_(char **tokens, env_t *linkedlist_path);
int _atoi(char *s);
int _isdigit(int c);
char *intiger_to_string(int c);
void free_tokens(char **tokens);
int main(int ac, char **av)
{
	char *line, *new_line, **token;
	size_t size = 0;
	ssize_t characters = 0;
	int counter = 0;
    env_t *linkedlist_path;


	(void)ac;
    (void)av;
    linkedlist_path = list_from_path();
	while (1)
	{
		counter ++;
		if (isatty(STDIN_FILENO) == 1)
        _prompt();
		characters = getline(&line, &size, stdin);
		if (characters == EOF || characters == -1)
		{
			free(line);
			return (0);
		}


	}
	return (0);
}
int _strlen(char *s)
{
	int i;

	for (i = 0; *(s + i) != '\0'; i++)
		;
	return (i);
}
int _strncmp(char *s1, char *s2, size_t bytes)
{
	unsigned int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (i = 0; s1[i] && s2[i] && s2[i] == s1[i] && i < bytes - 1; i++)
		;
	return (s2[i] - s1[i]);
}
char *_strcat_realloc(char *dest, char *src)
{
	unsigned int dest_len, src_len, i;

	dest_len = _strlen(dest);
	src_len = _strlen(src);
	dest = _realloc(dest, dest_len, dest_len + src_len + 1);
	if (dest == NULL)
		return (NULL);
	for (i = 0; i < src_len; i++)
	{
		dest[i + dest_len] = src[i];
	}
	dest[i + dest_len] = '\0';
	return (dest);
}
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
int _isdigit(int c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}
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
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *tmp, *buff;
	unsigned int i;

	if (ptr == NULL)
	{
		buff = malloc(new_size);
		if (buff == NULL)
			return (NULL);
		return (buff);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		buff = malloc(new_size * sizeof(char));
		tmp = ptr;

		_memset(buff, '\0', new_size);
		for (i = 0; i < old_size; i++)
			buff[i] = tmp[i];
		free(ptr);
		return (buff);
	}
	return (ptr);
}
void _memset(char *str, int fill, int n)
{
	int i;

	for (i = 0; i < n; i++)
		str[i] = fill;
}
void _memcpy(char *dest, char *src, unsigned int bytes)
{
	unsigned int i;

	for (i = 0; i < bytes; i++)
		dest[i] = src[i];
}
void _prompt(void)
{
	write(STDOUT_FILENO,"simple shell $ ", 15);

}
env_t *add_node(env_t **head, char *str, unsigned int len)
{
	env_t *new, *walk;
	char *dupstr;

	if (str == NULL)
		return (NULL);
	dupstr = _strdup(str);
	if (dupstr == NULL)
		return (NULL);
	new = malloc(sizeof(env_t));
	if (new == NULL)
		return (NULL);
	new->str = dupstr;
	new->len = len;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	walk = *head;
	while (walk->next != NULL)
		walk = walk->next;
	walk->next = new;
	return (*head);
}
char *_getenv(const char *name)
{
	int i, j, len;
	char **env, *tmp;

	if (!name)
		return (NULL);

	env = environ;
	for (i = 0; env[i]; i++)
	{
		for (len = 0; env[i][len] != '='; len++)
			;
		len++;
		tmp = malloc((len) * sizeof(char));
		if (tmp == NULL)
			return (NULL);

		_memcpy(tmp, env[i], len - 1);
		tmp[len - 1] = '\0';
		if (_strncmp((char *)name, tmp, _strlen(tmp)) == 0)
		{
			free(tmp);
			tmp = NULL;
			for (j = 0; env[i][j]; j++)
			{
				if (env[i][j] == '=')
				{
					tmp = &env[i][j + 1];
					break;
				}
			}
			return (tmp);
		}
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}
env_t *list_from_path(void)
{
	unsigned int len, i, j;
	char *env;
	char buffer[1024];
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