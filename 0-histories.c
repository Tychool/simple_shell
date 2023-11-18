#include "shell.h"

/**
 * th_history_pth - fetch history from a file path
 * @data: data
 *
 * Return: history file
 */
char *th_history_pth(data_t *data)
{
	char *folder = th_env_value(data, "HOME=");

	if (folder == NULL)
	return (NULL);

	size_t file_len = th_strlen(H_PTH);
	size_t folder_size = th_strlen(folder);
	char *arrays = malloc(folder_size + file_len + 2);

	if (arrays == NULL)
		return (NULL);

	th_strcpy(arrays, folder);

	if (folder[folder_size - 1] != '/')
		th_strcat(arrays, "/");

	th_strcat(arrays, H_PTH);

	return (arrays);
}

/**
 * th_history_list - create a list of historie
 *
 * @data: data
 * @arrays: arrays of history from file
 * @lindex: index at a line
 * Return: Always 0.
 */
int th_history_list(data_t *data, char *arrays, int lindex)
{
	list_t *nd = NULL;

	th_nde_add(&nd, arrays, lindex);

	if (data->his == NULL)
		data->his = nd;
	return (0);
}

/**
 * th_history_index - index history list
 * @data: data
 * Return: index
 */
int th_history_index(data_t *data)
{
	int count = 0;

	for (list_t *nd = data->his; nd; nd = nd->nxt)
	nd->nn = count++;
	return (data->his_line = count);
}

 /**
 * th_history_rd - read history file
 * @data: data
 * Return: history
 */
int th_history_rd(data_t *data)
{
	int i, end;
	int line = 0;
	char *arrays = NULL;
	char *file = th_history_pth(data);
	ssize_t filesize = 0;
	ssize_t fd, llen;

	struct stat st;

	if (file == NULL || (fd = open(file, O_RDONLY)) == -1)
	{
		return (free(file), 0);
	}

	free(file);
	if (!fstat(fd, &st) || (filesize = st.st_size) < 2 ||
			(arrays = malloc(filesize + 1)) == NULL)
		return (close(fd), 0);
	llen = read(fd, arrays, filesize);

	close(fd);

	if (llen <= 0)
	{
		return (free(arrays), 0);
	}
	arrays[filesize] = 0;
	for ( i = 0, end = 0; i < filesize; i++)
	{
		if (arrays[i] == '\n')
		{
			arrays[i] = 0;
			th_history_list(data, arrays + end, line++);
			end = i + 1;
		}
	}
	if (end != filesize)
		th_history_list(data, arrays + end, line++);

	free(arrays);
	data->his_line = line;

	while (data->his_line-- >= H_MAX)
		th_ndi_del(&(data->his), 0);

	th_history_index(data);
	return (data->his_line);
}
