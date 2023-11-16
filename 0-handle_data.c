#include "shell.h"

/**
 * th_setdata - set data_t
 * @data: data
 * @argv: argument vector
 * Return: Always 0.
 */
void th_setdata(data_t *data, char **argv)
{
	data->name = argv[0];

	if (data->arguments)
	{
		data->arg_vector = th_tok_strtow(data->arguments, TAB) ?:
		(char *[]){th_strdup(data->arguments), NULL};

		data->arg_count = data->arg_vector ? th_str_cnt(data->arg_vector) : 0;

		if (data->arg_vector)
		{
			th_aliasreplace(data);
			th_var_r(data);
		}
	}
}

/**
 * th_cleardata - Initializes the fields of the info_t struct
 * clear all
 * @data: info Pointer to the data_t struct to be initialized.
 */
void th_cleardata(data_t *data)
{
	data->arg_vector = NULL;
	data->arguments = NULL;
	data->pth_ad = NULL;
	data->arg_count = 0;
}

/**
 * th_freedata - free data_t list
 * @data: data
 * @free_all: free all
 * nothing
 */
void th_freedata(data_t *data, int free_all)
{
	th_freesos(data->arg_vector);
	data->arg_vector = NULL;
	data->pth_ad = NULL;

	if (free_all)
	{
		if (!data->cmd_buffer)
			free(data->arguments);
		if (data->env_cp)
			th_freel(&(data->env_cp));
		if (data->alias)
			th_freel(&(data->alias));
		if (data->his)
			th_freel(&(data->his));

		th_freesos(data->env_mod);
		data->env_mod = NULL;

		th_freeptr((void **)data->cmd_buffer);

		if (data->fd_r > 2)
			close(data->fd_r);

		th_putchar(FREE_BUFFER);
	}
}
