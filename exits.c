#include "shell.h"

/**
 * *th_strncpy - copies a string
 * @to: string to be copied
 * @from: from the source string
 * @n: number of strings
 * Return: Void
 */

char *th_strncpy(char *to, char *from, int n)
{
	int i, j;
	char *s = to;

	i = 0;

	while (from[i] != '\0' && i < n - 1)
	{
		to[i] = from[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			to[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * *th_strncat - concatenates two strings
 * @to: the first string
 * @from: the second string
 * @n: number of strings
 * Return: Void
 */

char *th_strncat(char *to, char *from, int n)
{
	int i, j;
	char *s = to;

	i = 0;
	j = 0;

	while (to[i] != '\0')
		i++;
	while (from[j] != '\0' && j < n)
	{
		to[i] = from[j];
		i++;
		j++;
	}
	if (j < n)
		to[i] = '\0';
	return (s);
}

/**
 * *th_strchr - locate a character in a string
 * @s: the string
 * @c: the character
 * Return: Void
 */

char *th_strchr(char *s, char c)
{
	do 
	{
	if (*s == c)
	return (s);
	} while (*s++ != '\0');
	return (NULL);
}
