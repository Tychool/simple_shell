#include "shell.h"

/**
 * th_shellrun - run the shell
 * @data: data
 * @argv: arg vector
 * Return: 0
 */
int th_shellrun(data_t *data, char **argv)
{
	int srun = 0;

	while (th_getinput(data) != -1 && srun != -2)
	{
		th_cleardata(data);
		if (th_is_inter(data))
			th_puts("$ ");
		th_erroutc(FREE_BUFFER);

		if (th_setdata(data, argv) == -1)
		{
			srun = th_find_cmd(data);

			if (srun == -1)
				srun == th_cmdPTH(data);
		}
	}
	th_history_w(data);
	th_freedata(data, 1);

	if (!th_is_inter(data) && data->cmd_stat)
		exit(data->cmd_stat);
	if (srun == -2)
		exit((data->error_no == -1) ?
		data->cmd_stat : data->error_no);
	return (srun);
}
