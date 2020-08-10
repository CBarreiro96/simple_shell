#include "holberton.h"

char *_getline(int file)
{
	unsigned int i, index;
	char *buffer;

	static unsigned int buffer_size = BUFSIZE;

	buffer = malloc(sizeof(char) * buffer_size);
	if (buffer == NULL)
	{
/* Messages of standar error and identify this as error*/
		perror("malloc for buffer failed\n");
		return (NULL);
	}
	index = 0;
/*Fill a block of memory with the buffer_size*/
	_memset(buffer, '\0', buffer_size);
	while ((i = read(file, buffer + index, buffer_size - index)) > 0)
	{

		if (i < (buffer_size - index))
			return (buffer);
		buffer_size *= 2;
		_realloc(buffer, buffer_size, buffer_size / 2);
		if (buffer == NULL)
		{
/* Messages of standar error and identify this like error*/
			perror("realloc failed\n");
			return (NULL);
		}
		index += i;
	}
	if (i == 0)

		_memcpy(buffer, "exit", 5);
	return (buffer);
}