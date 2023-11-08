#include "shell.h"
/**
 * th_firstLetter - compares first letters of given strings
 *
 * @haystack: block of string
 * @needle: first letter to check
 *
 * Return: Address of the next letter
 * or NULL on error.
 */
char *th_firstLetter(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack)
		{
			return (NULL);
		}
	}
	return ((char *)haystack);
}

/**
 * th_strcat - concat two given strings
 *
 * @to: where to append new string
 * @from: string to add
 *
 * Return: address of concat'ed string
 */
char *th_strcat(char *to, char *from)
{
	char *cat = to;

	while (*to)
	{
		to++;
	}
	while (*from)
	{
		*to++ = *from++;
	}
	*to = *from;
	return (cat);
}

/**
 * th_stoi - convert given string to int
 *
 * @s: string in
 *
 * Return: converted int or 0 if no number.
 */
int th_stoi(char *s)
{
	int i; /*index*/
	int sign = 1;
	int count = 0; /*counting flag*/
	int out; /*output*/
	unsigned int convert; /*the result*/

	for (i = 0; s[i] != '\0' && count != 2; i++)
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			count = 1;
			convert *= 10;
			convert += (s[i] -'0');
		}
		else if (count == 1)
		{
			count = 2;
		}
	}
	if (sign == -1)
	{
		out = -convert;
	}
	else
	{
		out = convert;
	}
	return (out);
}

/**
 * th_str_overwrite - overwrite a string
 *
 * @oldstr: pointer to old string
 * @newstr: pointer to new string
 *
 * Return: 1 on success, 0 - fail
 */
int th_str_overwrite(char **oldstr, char *newstr)
{
	free(*oldstr);
	*oldstr = newstr;

	if (!oldstr)
	{
		return (0);
	}
	return (1);
}
