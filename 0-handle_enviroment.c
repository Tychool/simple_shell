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
