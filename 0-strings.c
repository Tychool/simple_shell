#include "shell.h"
/**
 * th_strcpy - copy a given string
 *
 * @from: source
 * @to: copy to
 * Return: Address of copied string
 */
char *th_strcpy(char *to, char *from)
{
	int i = 0;

	if (to == from || from == 0)
	{
		return (to);
	}
	while (from[i])
	{
		to[i] = from[i];
		i++;
	}
	to[i] = 0;
	return (to);
}

/**
 * th_strdup - duplicate a given string
 *
 * @str: string input
 *
 * Return: address of new string
 */
char *th_strdup(const char *str)
{
	int s_len = 0;
	char *dup;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str++)
	{
		s_len++;
	}
	/*malloc for duplicate (dup)*/
	dup = malloc(sizeof(char) * (s_len + 1));
	/*check if malloc fails*/
	if (!dup)
		return (NULL);
	for (s_len++; s_len--;)
	{
		dup[s_len] = *--str;
	}
	return (dup);
}

/**
 * th_strlen - return length of a given string
 *
 * @s: given string
 * Return: strlen
 */
int th_strlen(char *s)
{
	int i = 0;

	if (!s)
	{
		return (0);
	}
	while (*s++)
	{
		i++;
	}
	return (i);
}

/**
 * th_strcmp - compare two given strings
 *
 * @str1: first input
 * @str2: second input
 *
 * Return: if str1 < str2 return -1, if
 * str1 > str2 return +1. if str1 == str2, return 0
 */
int th_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
			str1++;
			str2++;
		}
	}
	if (*str1 == *str2)
	{
		return (0);
	}
	else
	{
		return (*str1 < *str2 ? -1 : 1);
	}
}
