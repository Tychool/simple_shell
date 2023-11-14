#include "shell.h"

/**
 * th_perror - print error message accordingly
 *
 * @data: data in (struct)
 * @errmsg: error message (strings)
 */
void th_perror(data_t *data, char *errmsg)
{
	if (data == NULL || errmsg == NULL)
	{
		return;
	}
	char *name = data[0].name;
	while (*name != '\0')
	{
		th_erroutc(*name);
		name++;
	}
	/*standard error outpu*/
	th_erroutc(':');
	th_pdec(data[0].error_index, STDERR_FILENO);

	/*prog name*/
	th_erroutc(':');
	char *prog_name = data[0].arg_vector[0];
	while (*prog_name != '\0')
	{
		th_erroutc(*prog_name);
		prog_name++;
	}
	/*error*/
	th_erroutc(':');
	char *msg = errmsg;
	while (*msg != '\0')
	{
		th_erroutc(*msg);
		msg++;
	}
}
