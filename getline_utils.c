#include "shell.h"

/**
 * th_signal_handler - handle signal see SIGINT
 * Return: nothing
 */
void th_signal_handler(__attribute__((unused))int no)
{
	th_puts("\n$");
	th_putchar(FREE_BUFFER);
}

/**
 * th_buffer_in - command buffer
 * @data: data
 * @cmd_array: array of commands
 * @array_len: array lenght
 * Return: no of bytes
 */
ssize_t th_buffer_in(data_t *data, char **cmd_array, size_t *array_len)
{
	size_t mem_read;
	size_t tmp_len;

	if (!*array_len)
	{
		free(*cmd_array);
		*cmd_array = NULL;
		signal(SIGINT, th_signal_handler);

		mem_read = GET_LINE ? getline(cmd_array, &tmp_len, stdin) :
		th_get_line(data, cmd_array, &tmp_len);

		if (mem_read > 0)
		{
			if ((*cmd_array)[mem_read - 1] == '\n')
			{
				(*cmd_array)[--mem_read] = '\0';
			}

			data->current_line = 1;
			th_nocomments(*cmd_array);
			th_history_list(data, *cmd_array, data->his_line++);

			if (th_strchr(*cmd_array, ';'))
			{
				*array_len = mem_read;
				data->cmd_buffer = cmd_array;
			}
		}
	}
	return (mem_read);
}

/**
 * th_getinput - get user input
 * @data: every line other than new line
 * Return: number of bytes
 */
ssize_t th_getinput(data_t *data)
{
	static char *chain = NULL;
	static size_t chain_start = 1;
	static size_t chain_end = 0;

	th_putchar(FREE_BUFFER);

	ssize_t mem_read = th_buffer_in(data, &chain, &chain_end);

	if (mem_read == -1)
		return (-1);

	char **cmd_f = &(data->arguments);

	if (chain_end)
	{
		chain_start = chain_end;
		th_can_chcont(data, chain, &chain_start,
		chain_end, chain_start);

		while (chain_start < chain_end)
		{
			if (th_iscmd_c(data, chain, &chain_start))
				break;
			chain_start++;
		}
		*cmd_f = chain + chain_end;
		chain_end = chain_start + 1;

		if (chain_end >= chain_start)
		{
			chain_start = chain_end = 0;
			data->buffer_t = C_NORMAL;
		}
		return (th_strlen(*cmd_f));
	}
	*cmd_f = chain;
	return (mem_read);
}

/**
 * th_readbuffer - read buffer
 * @data: data
 * @arrays: buffer array
 * @size: size
 * Return: 0
 */
ssize_t th_readbuffer(data_t *data, char *arrays, size_t *size)
{
	if (*size)
		return (0);
	ssize_t mem_read = read(data->fd_r, arrays, READ_BUFFER);

	if (mem_read >= 0)
		*size = mem_read;
	return (mem_read);
}
