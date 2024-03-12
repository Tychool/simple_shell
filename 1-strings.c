#include "shell.h"


/**
 * th_splitstring - string to words
 * @str: string
 * @delim: delimiter
 * Return: words
 */

char **th_splitstring(char *str, const char *delim)
{
	int i, j;
	char **array;
  
	char *copy;
	char *tok;

	copy = malloc(th_strlen(str) + 1);
	if (copy == NULL)
	{
		perror(th_getenv("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';

	tok = strtok(copy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = th_strdup(tok);

	i = 1;
	j = 3;
	while (tok)
	{
		tok = strtok(NULL, delim);
		array = th_realloc(array, (sizeof(char *) * (j - 1)), (sizeof(char *) * j));
		array[i] = th_strdup(tok);
		i++;
		j++;
	}
	free(copy);
	return (array);
}
