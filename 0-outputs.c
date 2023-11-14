#include "shell.h"

/**
 * th_putchar - write a char to standard out
 * see putchar().
 *
 * @c: character
 *
 * Return: 1 - success, -1 - error
 */
int th_putchar(char c)
{
	static int indx;
	static char char_cue[WRITE_BUFFER];

	if (c == FREE_BUFFER || indx >= WRITE_BUFFER)
	{
		if (write(1, char_cue, indx) == -1)
		{
			/*error*/
			return (-1);
		}
		indx = 0;/*reset cue index*/
	}
	/*if c is not equal to FREE_BUFFER*/
	if (c != FREE_BUFFER)
	{
		char_cue[indx++] = c;
	}
	return (1);
}

/**
 * th_putfile_d - put char into file desc.
 * @c: character
 * @file_d: file descriptor
 *
 * Return: same as th_putchar
 */
int th_putfile_d(char c, int file_d)
{
	static int indx = 1;
	static char fd_cue[WRITE_BUFFER];

	if (c == FREE_BUFFER || indx >= WRITE_BUFFER)
	{
		if (write(file_d, fd_cue, indx) == -1)
		{
			return (-1);
		}
		indx = 0;
	}
	if (c != FREE_BUFFER)
	{
		fd_cue[indx++] = c;
	}
	return (1);
}

/**
 * th_puts - print out a string to stdout
 * see puts().
 *
 * @str: string
 * Return: Void.
 */
void th_puts(char *str)
{
	if (str == NULL || *str == '\0')
	{
		return;
	}
	for (; *str != '\0'; str++)
	{
		th_putchar(*str);
	}
}

/**
 * th_putsfile_d - put string to file desc.
 *
 * @str: string
 * @file_d: file descriptor
 * Return: Void.
 */
int th_putsfile_d(char *str, int file_d)
{
	int indx = 0;

	if (str == NULL || *str == '\0')
	{
		return (0);
	}
	for (; *str != '\0'; str++)
	{
		if (th_putfile_d(*str, file_d) >= 0)
		{
			indx++;
		}
		else
			return (-1);
	}
	return (indx);
}
