#include "shell.h"

/**
 * get_history_file - fetch history from a file path
 * @data: data
 *
 * Return: history file
 */
char *get_history_file(data_t *data)
{
	char *folder = th_printenv(data, "HOME=");

	if (folder == NULL)
	return (NULL);

	size_t file_len = _strlen(H_PTH);
	size_t folder_size = _strlen(folder);
	char *arrays = malloc(folder_size + file_len + 2);

	if (arrays == NULL)
		return (NULL);

	th_strcpy(arrays, folder);

	if (folder[folder_size - 1] != '/')
		th_strcat(arrays, "/");

	th_strcat(arrays, H_PTH);

	return (arrays);
}
