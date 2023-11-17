#include "shell.h"

/**
 * main - shell
 * @argv - arg vector
 * @argc - arg count
 *
 * Return 0
 */
int main(int argc, char **argv)
{
	welcome();

	int fd = 2;
	data_t data[] = {INIT_DATA};

	fd = open(argc == 2 ? argv[1] : "dev/null", O_RDONLY);
	if (fd == -1)
	{
		if (errno == ENOENT)
			return (fprintf(stderr, "%s: Can't open file %s\n",
			argv[0], argv[1]), 127);
		return (EXIT_FAILURE);
	}
	data->fd_r = fd;
	th_history_rd(data);
	th_shellrun(data, argv);

	return (EXIT_SUCCESS);
}
