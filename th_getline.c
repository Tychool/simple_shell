#include "shell.h"

/**
 * th_get_line - get line from STDIN
 *
 * @data: data
 * @lineptr: line
 * @line_len: length
 * Return: bytes read
 */
int th_get_line(data_t *data, char **lineptr, size_t *line_len)
{
	size_t i;
	ssize_t line = 0;
	static char arrays[READ_BUFFER];
	static size_t indx, lenght;
	(void)data;

	if (line == -1 || (line == 0 && lenght == 0))
		return (-1);
	char *ptr = *lineptr;
	size_t size = ptr && line_len  ? *line_len : 0;
	char *count = th_strchr(arrays + 1, '\n');

	i = count ? 1 + (unsigned int)(count - arrays) : lenght;

	char *nptr = th_realloc(ptr, size, size ? size + i : i + 1);

	if (!nptr)
		return (ptr ? free(ptr), -1 : -1);
	if (size)
		th_strncat(nptr, arrays + indx, i - indx);
	else
		th_strncpy(nptr, arrays + indx, i - indx + 1);

	size = size + i - indx;
	indx = i;
	ptr = nptr;

	if (line_len)
		*line_len = size;

	*lineptr = ptr;
	return (size);
}
