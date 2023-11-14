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
	return (th_isatty(STDIN_FILENO) && data->fd_r <= 2);
}

/**
 * th_iscommand - check if input stream is a command
 *
 * @data: data
 * @pth_ad: file path
 *
 * Return: 1 if its a command, 0 if not
 */
int th_command(data_t *data, char *pth_ad)
{
	struct stat cmd_st;

	return (pth_ad == NULL || stat(pth_ad, &cmd_st) ? 0 : (cmd_st.st_mode & S_IFREG));
}
