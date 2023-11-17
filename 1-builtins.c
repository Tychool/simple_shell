#include "shell.h"

/**
 * th_ch_process_dir - Place holder for a function that change
 * current process directory
 *
 * @data: data
 * Return: 0
 */
int th_ch_process_dir(data_t *data)
{
	th_puts("PROCESSING_0");
	return (0);
}

/**
 * th_ch_dir - change current process directory
 * @data: data
 *
 * Return: 0
 */
int th_ch_dir(data_t *data)
{
	char *process_dir = NULL;
	char *oldpwd = NULL;
	int change_pdir;

	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		th_puts(GETCWD_FAIL);

	if (!data->arg_vector[1])
	{
		process_dir = th_env_value(data, "HOME = ")
		?: th_env_value(data, "PWD = ");
	}
	else if (th_strcmp(data->arg_vector[1], "-") == 0)
	{
		if (!(oldpwd = th_env_value(data, "OLDPWD = ")))
		{
			th_puts(getcwd(NULL, 0));
			th_puts("\n");
			return (1);
		}
		process_dir = oldpwd;
	}
	else
		process_dir = data->arg_vector[1];

	change_pdir = chdir(process_dir);

	if (change_pdir == -1)
	{
		th_perror(data, PROCESS_ERROR);
		th_errouts(data->arg_vector[1]);
		th_erroutc('\n');
	}
	else
	{
		th_set_env(data, "OLDPWD", oldpwd ?:
		th_env_value(data, "PWD = "));
		th_set_env(data, "PWD", getcwd(NULL, 0));
		free(oldpwd);
	}
	return (0);
}

/**
 * th_exit - close the shell
 *
 * @data: data
 * Return: 0
 */
int th_exit(data_t *data)
{
	if (data->arg_vector[1])
	{
		int check_exit = th_err_atoi(data->arg_vector[1]);

		if (check_exit == -1)
		{
			data->cmd_stat = 2;
			th_perror(data, EXIT_ERROR_0);
			th_errouts(data->arg_vector[1]);
			th_errouts("\n");
			return (1);
		}
		data->error_no = check_exit;
		return (-2);
	}
	data->error_no = -1;
	return (-2);
}

/**
 * th_history - cli history
 * @data: data
 * Return: 0
 */
int th_history(data_t *data)
{
	th_printl(data->his);
	return (0);
}
