#include "shell.h"

/**
 * th_set_env - set up a new/modify enviroment variable
 *
 * @data: data
 * @variable: variable
 * @env_value: value for env variable
 *
 * Return: 0.
 */
int th_set_env(data_t *data, char *variable, char *env_value)
{
	if (variable == NULL || env_value == NULL)
		return (0);

	char *arrays = malloc(th_strlen(variable) + th_strlen(env_value) + 2);

	if (arrays == NULL)
		return (1);

	th_strcpy((th_strcat(arrays, variable), "="), env_value);

	list_t *nd = data->env_cp;

	while (nd && !(th_firstletter(nd->str, variable)
	&& nd->str[th_strlen(variable)] == '='))
		nd = nd->nxt;

	if (nd != NULL)
	{
		free(nd->str);
		nd->str = arrays;
	}
	else
		th_nde_add(&(data->env_cp), arrays, 0);
	free(arrays);
	data->env_ch = 1;
	return (0);
}

/**
 * th_get_env - fetch enviroment
 * @data: data
 * Return: adress to envioroment var
 */
char **th_get_env(data_t *data)
{
	if (data->env_cp || data->env_mod == NULL)
	{
		free(data->env_mod);
		data->env_mod = th_ltos(data->env_cp);
		data->env_ch = 0;
	}
	return (data->env_mod);
}

/**
 * th_unset_env - delete enviroment var
 * @data: data
 * @variable: variable
 * Return: 1.
 */
int th_unset_env(data_t *data, char *variable)
{
	if (data->env_cp == NULL || variable == NULL)
		return (0);

	char *prop_match;
	list_t *current_nd = data->env_cp;
	size_t nd_indx = 0;

	while (current_nd)
	{
		prop_match = th_firstletter(current_nd->str, variable);
		if (prop_match != NULL && *prop_match == '=')
		{
			data->env_ch = th_ndi_del(&(data->env_cp), nd_indx);
			current_nd = current_nd->nxt;
			nd_indx = 0;
		}
		else
		{
			current_nd = current_nd->nxt;
			nd_indx++;
		}
	}
	return (data->env_ch);
}

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
		th_unset_env(data, data->arg_vector[i]);
	return(0);
}
