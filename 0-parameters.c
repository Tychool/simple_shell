#include "shell.h"

/**
 * th_isatty - check if a file descriptor is associated with terminal
 *
 * @fd: file descriptor
 *
 * Return: a non zero value if true, otherwise return 0.
 */
int th_isatty(int fd)
{
	return (fd >= 0 && fd <= 2);
}

/**
 * th_isalpha - check for alphabet character
 * @c: char input
 * Return: 1 if true, 0 otherwise
 */
int th_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * th_isDelimeter - check a character and determine
 * if it's a delimeter
 *
 * @c: the char to check
 * @delimeter: the delimeter string
 * Return: 1 if true, 0 if false
 */
int th_isDelimeter(char c, char *delimeter)
{
	while (*delimeter != '\0')
	{
		if (*delimeter == c)
	{
		return (1);  /*Found the delimeter*/
	}
		delimeter++;
	}

	return (0);  /*Not a delimiter*/
}

