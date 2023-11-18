#include "shell.h"

/**
 * th_shellrun - run the shell
 * @data: data
 * @argv: arg vector
 * Return: 0
 */
int th_shellrun(data_t *data, char **argv)
{
	ssize_t srun;
	int t;

	do {
		th_cleardata(data);
		if (th_is_inter(data))
			th_puts("$ ");

		th_erroutc(FREE_BUFFER);
		srun = th_getinput(data);

		if (srun != -1)
		{
			th_setdata(data, argv);
			t = th_findcmd(data);

			if (t == -1)
				th_cmdPTH(data);
		}
		else if (th_is_inter(data))
			th_putchar('\n');

		th_freedata(data, 0);
	} while (srun != -1 && t != -2);

	th_history_w(data);
	th_freedata(data, 1);

	if (!th_is_inter(data) && data->cmd_stat)
		exit(data->cmd_stat);

	if (t == -2)
		exit(data->error_no == -1 ? data->cmd_stat : data->error_no);

	return (t);
}
