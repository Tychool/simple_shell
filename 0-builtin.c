#include "shell.h"

/**
 * th_alias - implement alias builtin
 * @data: data
 * Return: 0
 */
int th_alias(data_t *data)
{
	char *alias_ptr = NULL;
	list_t *nd = NULL;
	int i = 0;

	if (data->arg_count == 1)
	{
		for (nd = data->alias; nd; nd = nd->nxt)
			th_printas(nd);
		return (0);
	}
	for (i = 1; data->arg_vector[i]; i++)
	{
		alias_ptr = th_strchr(data->arg_vector[i], '=');
		if (alias_ptr)
			th_aliastostr(data, data->arg_vector[i]);
		else
			th_printas(th_ndFirst(data->alias, data->arg_vector[i], '='));
	}
	return (0);
}

/**
 * th_printas - print alias
 * @nd: node
 * Return: 1
 */
int th_printas(list_t *nd)
{
	if (nd)
	{
		char *alias_ptr = th_strchr(nd->str, '=');

		th_puts("'");
		for (char *alias_str = nd->str; alias_str <= alias_ptr;
		th_putchar(*alias_str++))
			;
		th_puts(alias_ptr + 1);
		th_puts("\n");
		return (0);
	}
	return (1);
}

/**
 * th_aliastostr - set alias to strings
 * @data: data
 * @str: strings
 * Return: 0
 */
int th_aliastostr(data_t *data, char *str)
{
	char *alias_ptr = th_strchr(str, '=');

	if (!alias_ptr || !*++alias_ptr)
		return (th_init_aliastostr(data, str));
	return (th_nde_add(&(data->alias), str, 0) == NULL);
}

/**
 * th_init_aliastostr - initialise setting alias to string
 * @data: data
 * @str: string
 * Return: 0
 */
int th_init_aliastostr(data_t *data, char *str)
{
	char *equals = th_strchr(str, '=');

	if (!equals)
		return (1);
	char saved_char = equals[1];

	equals[1] = '\0';

	int init = th_ndi_del(&(data->alias), th_ndi_get(data->alias,
	th_ndFirst(data->alias, str, -1)));
	equals[1] = saved_char;
	return (init);
}
