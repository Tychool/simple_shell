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
int th_iscommand(data_t *data, char *pth_ad)
{
	struct stat cmd_st;

	return (pth_ad == NULL || stat(pth_ad, &cmd_st)
	? 0 : (cmd_st.st_mode & S_IFREG));
}

/**
 * th_iscmd_c - check if the current character is a chain delimeter
 *
 * @data: data
 * @arrays: character array
 * @current_index: ptr to current position in buffer
 *
 * Return: 1 = true, 0 = false
 */
int th_iscmd_c(data_t *data, char *arrays, size_t *current_index)
{
	size_t current_position = *current_index;

	/*
	 * Check for '||' or '&&' indicating logical OR or AND
	 * and set logic operator accordingly
	 */
	if ((arrays[current_position] == '|'
	&& arrays[current_position + 1] == '|') ||
	(arrays[current_position] == '&'
	&& arrays[current_position + 1] == '&'))
	{
		arrays[current_position] = 0;
		current_position++;
		data->buffer_t = (arrays[current_position - 1]
		== '|') ? C_OR : C_AND;
	}
	/*Check for ';' indicating end of command*/
	else if (arrays[current_position] == ';')
	{
		arrays[current_position] = 0;
		data->buffer_t = CH_CMD;
	}
	else
	{
		return (0);
	}
	*current_index = current_position;
}

/**
 * th_can_chcont - check if a chan can be continued
 *
 * @data: data
 * @arrays: character arrays
 * @current_index: same as in th_iscmd_c()
 * @start: egining of line
 * @alen: array lenght
 */
void th_can_chcont(data_t *data, char *arrays,
		size_t *current_index, size_t start, size_t alen)
{
	size_t current_position = *current_index;

	if ((data->buffer_t == C_AND && data->cmd_stat) ||
	(data->buffer_t == C_OR && data->cmd_stat == '\0'))
	{
		arrays[start] = 0;
		current_position = alen;
	}
	*current_index = current_position;
}

