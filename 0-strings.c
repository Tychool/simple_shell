#include "shell.h"

/**
 * th_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int th_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * th_puts - print string
 * @str: string
 */

void th_puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		th_putchar(str[i]);
		i++;
	}
}

/**
 * th_strlen - compute string length of a given string
 * @s: string
 * Return: strlen
 */
int th_strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * th_strdup - duplicate string
 * @str: pointer to string
 * Return: pointer to duplicate of string
 */
char *th_strdup(char *str)
{
	int i, j;
	char *new;

	if (!str)
	{
		return (NULL);
	}
	j = 0;
  while (str[j] != '\0')
  {
    j++;
  }
	new = malloc(sizeof(char) * j + 1);
	if (!new)
	{
		return (NULL);
	}
	for (i = 0; i < j; i++)
	{
		new[i] = str[i];
	}
	new[j] = str[j];
	return (new);
}

/**
 * th_concat_all - concatenate all strings
 * @name: name
 * @sep: seperator
 * @value: value
 * Return: pointer to the new string
 */
char *th_concat_all(char *name, char *sep, char *value)
{
	char *result;
	int slen1, slen2, slen3, i, k;

	slen1 = th_strlen(name);
	slen2 = th_strlen(sep);
	slen3 = th_strlen(value);

	result = malloc(slen1 + slen2 + slen3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

