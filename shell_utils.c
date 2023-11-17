#include "shell.h"

/**
 * th_findcmd - look for builtin commands
 * @data: data
 * Return: 0
 */
int th_findcmd(data_t *data)
{
	builtin_t table = {
		{"env", th_print_env},
		{"help", th_ch_process_dir},
		{"history", th_history},
		{"setenv", th_init_env},
		{"unsetenv", th_env_del},
		{"exit", th_exit_shell},
		{"cd", th_ch_dir},
		{"alias", th_alias},
		{NULL, NULL}
	};

	for (int i = 0, table[i].t; i++)
	{
		if (th_strcmp(data->arg_vector[0], table.t) == 0)
		{
			data->error_index++;
			int b_cmd = table[i].f(data);
		}
	}
	return (-1);
}

/**
 * th_fork - fork command
 * @data: data
 * Return: nothing
 */
void th_fork(data_t *data)
{
	pid_t cpid = fork();

	if (cpid == -1)
	{
		perror("Failed to create child process : ");
		return;
	}
	if (cpid == 0)
	{
		if (execve(data->pth_ad, data->arg_vector, th_get_env(data)) == 0)
		{
			th_freedata(data, 1);
			exit((errno == EACCES) ? 126 : 1);
		}
	}
	else
	{
		wait(&(data->cmd_stat));

		if (WIFEXITED(data->cmd_status))
		{
			data->cmd_stat = WEXITSTATUS(data->cmd_stat);
			if (data->cmd_stat == 126)
				th_perror(data, PROCESS_ERROR_1);
		}
	}
}

/**
 * th_cmdPTH - get command in path
 * @data: data
 */
void th_cmdPTH(data_t *data)
{
	char *cmd_pth = NULL;

	data->pth_ad = data->arg_vector[0];

	if (data->current_line == 1)
	{
		data->error_index++;
		data->current_line = 0;
	}
	int count = 0;

	for (int i = 0; data->arguments[i]; i++)
	{
		if (!th_isDelimeter(data->arguments[i], "\n"))
			count++;
	}
	if (!count)
		return;
	cmd_pth = th_pathfinder(data, th_env_value(data, PATH"="),
			data->arg_vector[0]);

	if (cmd_pth)
	{
		data->pth_ad = cmd_pth;
		th_fork(data);
	}
	else
	{
		if ((th_is_inter(data) || th_env_value(data,
		"PATH=") || data->arg_vector[0][0] == '/')
		&& th_is_exec(data, data->arg_vector[0]))
			th_fork(data);
		else if (*(data->arguments) != '\n')
		{
			data->cmd_stat = 127;
			th_perror(data, PROCESS_ERROR);
		}
	}
}
