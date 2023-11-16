#include "shell.h"

/**
 * th_init_env - initialize enviroment var
 * @data: data
 * Return 0
 */
int th_init_env(data_t *data)
{
	if (!th_set_env(data, data->arg_vector[1],
	data->arg_vector[2]) || data->arg_count != 3)
	{
		th_errouts(ARG_ERROR1);
		return (1);
	}
	return (0);
}

/**
 * th_print_env - print enviroment variable
 * @data: data
 * Return: enviroment variable
 */
int th_print_env(data_t *data)
{
th_printls(data->env_cp);
return (0);
}

/**
 * th_env_value - fetch enviroment value
 * @data: data
 * var_name: name of enviroment var
 * Return: env value
 */
char *th_env_value(data_t *data, const char *var_name)
{
	for (list_t *nd = data->env_cp; nd; nd = nd->nxt)
	{
		char *e_val = th_firstletter(nd->str, var_name);
		if (e_val && *e_val)
			return (e_val);
	}
	return (NULL);
}

/**
 * th_env_fill - fill enviroment list
 * @data: data
 * Return: 0
 */
int th_env_fill(data_t *data)
{
	for (size_t i = 0; data->env_mod[i]; i++)
		th_nde_add(&data->env_cp, data->env_mod[i], 0);
	return (0);
}

