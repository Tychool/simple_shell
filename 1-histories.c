#include "shell.h"

/**
 * th_history_w - writh into history path
 * @data: data
 * Return: 1
 */
int th_history_w(data_t *data)
{
	char *file = th_history_pth(data);

	if (file == NULL)
		return (-1);

	int fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 0644);

	free(file);

	if (fd == -1)
		return (-1);
	for (list_t *nd = data->his; nd; nd = nd->nxt)
	{
		th_putsfile_d(nd->str, fd);
		th_putfile_d('\n', fd);
	}
	th_putfile_d(FREE_BUFFER, fd);
	close(fd);
	return (1);
}
