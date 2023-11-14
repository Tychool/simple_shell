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

	if (to == from || from == NULL)
	{
		return (to);
	}
	while ((to[i] = from[i]) != '\0')
	{
		i++;
	}
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
	if (str == NULL)
	{
		return (NULL);
	}

	int s_len = 0;

	while (*str++)
	{
		s_len++;
	}
	/*malloc for duplicate (dup)*/
	char *dup = malloc(sizeof(char) * (s_len + 1));
	/*check if malloc fails*/
	if (dup == NULL)
	{
		return (NULL);
	}

	/*copy string in reverse order*/

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
	if (s == NULL)
	{
		return (0);
	}

	int i = 0;
	while (s[i] != '\0')
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
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
