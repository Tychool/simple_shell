#include "shell.h"

/**
 * th_erroutc - write char c to standard error
 *
 * @c: character
 *
 * Return: same as th_putchar
 */
int th_erroutc(char c)
{
	static int indx;
	static char char_cue[WRITE_BUFFER];

	if (c == FREE_BUFFER || indx >= WRITE_BUFFER)
	{
		if (write(2, char_cue, indx) == -1)
		{
			return (-1);
		}
		indx = 0;
	}
	if (c != FREE_BUFFER)
	{
		char_cue[indx++] = c;
	}
	return (1);
}

/**
 * th_errouts - write a string into standard error
 *
 * @str: string
 *
 * Return: Nothing
 */
void th_errouts(char *str)
{
	if (str == NULL || *str == '\0')
	{
		return;
	}
	int indx = 0;

	while (str[indx] != '\0')
	{
		th_erroutc(str[indx]);
		indx++;
	}
}

/**
 * th_err_atoi - same as atoi
 *
 * @s: string in
 *
 * Return: same as atoi().
 */
int th_err_atoi(char *s)
{
	if (s == NULL || *s == '\0')
	{
		return (INT_MIN);
	}

	int indx = 0;
	int sign = 1;
	unsigned long int res = 0;

	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
		{
			sign = -1;
		}
		s++;
	}

	for (indx = 0; s[indx] != '\0'; indx++)
	{
		if (s[indx] >= '0' && s[indx] <= 9)
		{
			res = res * 10;
			res = res + (s[indx] - '0');
		}
		else
		{
			return (INT_MIN);
		}
		/*check overflow*/
		if ((sign == 1 && res > (unsigned long int)INT_MAX) ||
				(sign == -1 && res < (unsigned long int)INT_MIN + 1))
		{
			return (INT_MIN);
		}
	}
	return (sign * (int)res);
}

/**
 * th_pdec - print int to fd
 *
 * @in: input
 * @file_d: fd
 *
 * Return: count of printed characters
 */
int th_pdec(int in, int file_d)
{
	int indx = 0;
	int (*_putchar)(char) = th_putchar;
	int denum = 1;
	int whole_num;

	if (file_d == STDERR_FILENO)
	{
		_putchar = th_erroutc;
	}
	if (in < 0)
	{
		_putchar('-');
		indx++;
		in = -in;
	}
	if (in == 0)
	{
		_putchar('0');
		indx++;
	}
	else
	{
		/*find the highest power of 10 <= in*/
		while (denum <= in / 10)
		{
			denum = denum * 10;
		}
		/*print each digit of the number*/
		while (denum > 0)
		{
			whole_num = in / denum;
			_putchar('0' + whole_num);/*print digit*/
			indx++;
			/*Update the calue if in and denum for next iteraton*/
			in = in % denum;
			denum = denum / 10; /*next lower decimal place*/
		}
	}
	return (indx);
}
