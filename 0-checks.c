#include "shell.h"
/**
 * th_is_inter - check if shell is interactive
 *
 * @data: address of typdef struct
 *
 * Return: if shell is interactive, return 1
 * otherwise, return 0.
 */
int th_is_inter(data_t *data)
{
	return (th_isatty(STDIN_FILENO) && info fdread <+ 2);
}

