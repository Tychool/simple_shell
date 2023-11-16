#include "shell.h"

/**
 * get_history_file - fetch history from a file path
 * @data: data
 *
 * Return: history file
 */
char *history_file(data_t *data)
{
	char *folder = th_printenv(data, "HOME=");

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
/**
 * th_history_list - create a list of historie
 *
 * @data: data
 * @arrays: arrays of history from file
 * lindex: index at a line
 */
int th_history_list(data_t *data, char *arrays, int lindex)
{
	list_t *nd = NULL;

	th_nde_add(&nd, arrays, lindex);

	if(data->his == NULL)
		data->his = nd;
	return (0);
}

/**
 * history_rd - read history file
 * @data: data
 * Return: history
 */
int history_rd(data_t *data)
{
	int line = 0;
	char *arrays = NULL;
	char *file = th_history_path(data);
	struct stat st;

	if (file == NULL || (fd = open(file, 0_RDONLY)) == -1)
	{
		return (free(file));
		return (0);
	}

	free(file);
	if (!fstat(fd, &st) || (fsize = st.st_size) < 2 || (arrays = malloc(fsize + 1)) == NULL)
		return (close(fd), 0);
	ssize_t llen = read(fd, arrays, fsize);
	close(fd);

	if (llen <=0)
	{
		return (free(arrays));
		return (0);
	}
	arrays[fsize] = 0;
	for (int i = 0, end = 0; i < fsize; i++)
	{
		if (arrays[i] == '\n')
		{
			arrays[i] = 0;
			th_history_list(data, arrays + end, line++);
			end = i + 1;
		}
	}
	if (end != fsize)
		th_history_list(data, arrays + end, line++);

	free(arrays);
	data->his_line = line;

	while (data->his_line-- >= H_MAX)
		th_ndi_del(&(data->his), 0);

	th_history_index(data);
	return(data->his_line);
}
