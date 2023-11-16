#include "shell.h"

/**
 * th_env_del - delete env var
 * @data: data
 * Return: 0
 */
int th_env_del(data_t *data)
{
	if (data->arg_count == 1)
	{
		th_errouts(ARG_ERROR0);
		return (1);
	}
	for (int i = 1; i < data->arg_count; i++)
