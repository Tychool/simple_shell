#include "shell.h"

/**
 * th_itoa - convert int to char
 *
 * @nn: number
 * @base: base (ie decimal = base10)
 * @line: current line
 * Return: pointer to the conversion
 */
char *th_itoa(long int nn, int base, int line)
{
	/*Define an array for digits in both lowercase and uppercase*/
	static const char *digits_lower = "0123456789abcdef";
	static const char *digits_upper = "0123456789ABCDEF";
	/*Buffer to store the converted string*/
	static char buffer[50];
	char *result = buffer;/*Pointer to the result string*/
	/*char sign = 0;*//*Sign indicator*/
	unsigned long n = (nn < 0 && !(line & CONV_UNSGND)) ? -nn : nn;
	/*Choose the appropriate array of digits based on the lowercase flag*/
	const char *array = (line & CONV_LCASE) ? digits_lower : digits_upper;
	/*Start from the end of the buffer*/
	result = result + sizeof(buffer) - 1;
	*result = '\0';
	/*Convert the number to the specified base*/
	do {
		*--result = array[n % base];
		n = n / base;
	} while (n != 0);
	/*Add sign if the number is negative and not an unsigned conversion*/
	if (nn < 0 && !(line & CONV_UNSGND))
		*--result = '-';
	return (result);
}

/**
 * th_nocomments - remove comments
 *
 * @arrays: strings
 *
 * Return: nothing
 */
void th_nocomments(char *arrays)
{
	if (arrays == NULL || *arrays == '\0')
	{
		return;
	}

	for (int i = 0; arrays[i] != '\0' && !(arrays[i] == '#'
	&& (i == 0 || arrays[i - 1] == ' ')); i++)
	{
		if (arrays[i] == '#' && (i == 0 || arrays[i - 1] == ' '))
		{
			arrays[i] = '\0';
		}
	}
}

/**
 * th_aliasreplace - replace alias
 *
 * @data: data
 *
 * Return: 1
 */
int th_aliasreplace(data_t *data)
{
list_t *nd;
int indx;

for (indx = 0; indx < 10; indx++)
{
	if (!(nd = th_ndFirst(data->alias, data->arg_vector[0], '=')))
	{
		return (0);
	}
	free(data->arg_vector[0]);
	data->arg_vector[0] = th_strdup(th_strchar(nd->str, '=') + 1);

	if (!data->arg_vector[0])

	{
		return (0);
	}
}
return (1);
}

/**
 * th_var_overwrite - replace a variable
 * @data: data
 * Return: same as prev func
 */
int th_var_overwrite(data_t *data)
{
	list_t *nd;
	int i = 0;

	while (data->arg_vector[i])
	{
		if (data->arg_vector[i][0] == '$' && data->arg_vector[i][1])
		{
			if (!th_strcmp(data->arg_vector[i], "$?"))
			{
				th_str_overwrite(&(data->arg_vector[i]),
			th_strdup(th_itoa(data->cmd_stat, 10,0)));
			}
			else if (th_strcmp(data->arg_vector[i], "$$") == '\0')
			{
				th_str_overwrite(&(data->arg_vector[i]),
				th_strdup(th_itoa(getpid(), 10,0)));
			}
			else if ((nd = th_ndFirst(data->env_cp,
				&data->arg_vector[i][1], '=')))
			{
				th_str_overwrite(&(data->arg_vector[i]),
				th_strdup(th_strchar(nd->str, '=')));
			}
			else
			th_str_overwrite(&data->arg_vector[i], th_strdup(""));
		}
		i++;
	}
	return (0);
}
